//
// Copyright (c) 2009, Markus Rickert
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#include <iostream>
#include <memory>
#include <stdexcept>
#include <boost/lexical_cast.hpp>
#include <rl/kin/Kinematics.h>
#include <rl/math/Unit.h>
#include <rl/plan/KdtreeNearestNeighbors.h>
#include <rl/plan/Prm.h>
#include <rl/plan/RecursiveVerifier.h>
#include <rl/plan/SimpleModel.h>
#include <rl/plan/SimpleOptimizer.h>
#include <rl/plan/UniformSampler.h>
#include <rl/sg/Model.h>

#ifdef RL_SG_BULLET
#include <rl/sg/bullet/Scene.h>
#endif // RL_SG_BULLET
#ifdef RL_SG_FCL
#include <rl/sg/fcl/Scene.h>
#endif // RL_SG_FCL
#ifdef RL_SG_ODE
#include <rl/sg/ode/Scene.h>
#endif // RL_SG_ODE
#ifdef RL_SG_PQP
#include <rl/sg/pqp/Scene.h>
#endif // RL_SG_PQP
#ifdef RL_SG_SOLID
#include <rl/sg/solid/Scene.h>
#endif // RL_SG_SOLID

int
main(int argc, char** argv)
{
	if (argc < 14)
	{
		std::cout << "Usage: rlPrmTest ENGINE SCENEFILE KINEMATICSFILE EXPECTED_NUM_VERTICES_MAX EXPECTED_NUM_EDGES_MAX X Y Z A B C START1 ... STARTn GOAL1 ... GOALn" << std::endl;
		return EXIT_FAILURE;
	}
	
	try
	{
		std::shared_ptr<rl::sg::Scene> scene;
		
#ifdef RL_SG_BULLET
		if ("bullet" == std::string(argv[1]))
		{
			scene = std::make_shared<rl::sg::bullet::Scene>();
		}
#endif // RL_SG_BULLET
#ifdef RL_SG_FCL
		if ("fcl" == std::string(argv[1]))
		{
			scene = std::make_shared<rl::sg::fcl::Scene>();
		}
#endif // RL_SG_FCL
#ifdef RL_SG_ODE
		if ("ode" == std::string(argv[1]))
		{
			scene = std::make_shared<rl::sg::ode::Scene>();
		}
#endif // RL_SG_ODE
#ifdef RL_SG_PQP
		if ("pqp" == std::string(argv[1]))
		{
			scene = std::make_shared<rl::sg::pqp::Scene>();
		}
#endif // RL_SG_PQP
#ifdef RL_SG_SOLID
		if ("solid" == std::string(argv[1]))
		{
			scene = std::make_shared<rl::sg::solid::Scene>();
		}
#endif // RL_SG_SOLID
		
		scene->load(argv[2]);
		
		std::shared_ptr<rl::kin::Kinematics> kinematics(rl::kin::Kinematics::create(argv[3]));
		
		rl::math::Transform world = rl::math::Transform::Identity();
		
		world = rl::math::AngleAxis(
			boost::lexical_cast<rl::math::Real>(argv[11]) * ::rl::math::DEG2RAD,
			::rl::math::Vector3::UnitZ()
		) * ::rl::math::AngleAxis(
			boost::lexical_cast<rl::math::Real>(argv[10]) * ::rl::math::DEG2RAD,
			::rl::math::Vector3::UnitY()
		) * ::rl::math::AngleAxis(
			boost::lexical_cast<rl::math::Real>(argv[9]) * ::rl::math::DEG2RAD,
			::rl::math::Vector3::UnitX()
		);
		
		world.translation().x() = boost::lexical_cast<rl::math::Real>(argv[6]);
		world.translation().y() = boost::lexical_cast<rl::math::Real>(argv[7]);
		world.translation().z() = boost::lexical_cast<rl::math::Real>(argv[8]);
		
		kinematics->world() = world;
		
		rl::plan::SimpleModel model;
		model.kin = kinematics.get();
		model.model = scene->getModel(0);
		model.scene = scene.get();
		
		rl::plan::KdtreeNearestNeighbors nearestNeighbors(&model);
		rl::plan::Prm planner;
		rl::plan::UniformSampler sampler;
		rl::plan::RecursiveVerifier verifier;
		
		sampler.seed(0);
		
		planner.model = &model;
		planner.setNearestNeighbors(&nearestNeighbors);
		planner.sampler = &sampler;
		planner.verifier = &verifier;
		
		sampler.model = &model;
		
		verifier.delta = 1.0f * rl::math::DEG2RAD;
		verifier.model = &model;
		
		rl::math::Vector start(kinematics->getDof());
		
		for (std::size_t i = 0; i < kinematics->getDof(); ++i)
		{
			start(i) = boost::lexical_cast<rl::math::Real>(argv[i + 12]) * rl::math::DEG2RAD;
		}
		
		planner.start = &start;
		
		rl::math::Vector goal(kinematics->getDof());
		
		for (std::size_t i = 0; i < kinematics->getDof(); ++i)
		{
			goal(i) = boost::lexical_cast<rl::math::Real>(argv[kinematics->getDof() + i + 12]) * rl::math::DEG2RAD;
		}
		
		planner.goal = &goal;
		
		planner.duration = std::chrono::seconds(20);
		
		std::cout << "construct() ... " << std::endl;;
		std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
		planner.construct(15);
		std::chrono::steady_clock::time_point stopTime = std::chrono::steady_clock::now();
		std::cout << "construct() " << std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime).count() * 1000 << " ms" << std::endl;
		
		std::cout << "solve() ... " << std::endl;;
		startTime = std::chrono::steady_clock::now();
		bool solved = planner.solve();
		stopTime = std::chrono::steady_clock::now();
		std::cout << "solve() " << (solved ? "true" : "false") << " " << std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime).count() * 1000 << " ms" << std::endl;
		
		std::cout << "NumVertices: " << planner.getNumVertices() << "  NumEdges: " << planner.getNumEdges() << std::endl;
		
		if (solved)
		{
			if (boost::lexical_cast<std::size_t>(argv[4]) >= planner.getNumVertices() &&
				boost::lexical_cast<std::size_t>(argv[5]) >= planner.getNumEdges())
			{
				return EXIT_SUCCESS;
			}
			else
			{
				std::cerr << "NumVertices and NumEdges are more than expected for this test case.";
				return EXIT_FAILURE;
			}
		}
		
		return EXIT_FAILURE;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
