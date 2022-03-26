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

#include <algorithm>
#include <Inventor/actions/SoGetMatrixAction.h>
#include <Inventor/actions/SoSearchAction.h>
#include <Inventor/VRMLnodes/SoVRMLInline.h>

#include "Body.h"
#include "Model.h"
#include "Scene.h"

namespace rl
{
	namespace sg
	{
		Model::Model(Scene* scene) :
			bodies(),
			scene(scene),
			name()
		{
		}
		
		Model::~Model()
		{
		}
		
		void
		Model::add(Body* body)
		{
			this->bodies.push_back(body);
		}
		
		Model::Iterator
		Model::begin()
		{
			return this->bodies.begin();
		}
		
		Model::Iterator
		Model::end()
		{
			return this->bodies.end();
		}
		
		Body*
		Model::getBody(const ::std::size_t& i) const
		{
			return this->bodies[i];
		}
		
		::std::string
		Model::getName() const
		{
			return this->name;
		}
		
		::std::size_t
		Model::getNumBodies() const
		{
			return this->bodies.size();
		}
		
		Scene*
		Model::getScene() const
		{
			return this->scene;
		}
		
		void
		Model::remove(Body* body)
		{
			Iterator found = ::std::find(this->bodies.begin(), this->bodies.end(), body);
			
			if (found != this->bodies.end())
			{
				this->bodies.erase(found);
			}
		}
		
		void
		Model::setName(const ::std::string& name)
		{
			this->name = name;
		}
	}
}
