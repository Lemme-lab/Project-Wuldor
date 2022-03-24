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

#include <rl/math/Rotation.h>

#include "Revolute.h"

namespace rl
{
	namespace mdl
	{
		Revolute::Revolute() :
			Joint(1, 1)
		{
			this->qUnits(0) = ::rl::math::UNIT_RADIAN;
			this->qdUnits(0) = ::rl::math::UNIT_RADIAN_PER_SECOND;
			this->qddUnits(0) = ::rl::math::UNIT_RADIAN_PER_SECOND_SQUARED;
			this->S(2, 0) = 1;
			this->speedUnits(0) = ::rl::math::UNIT_RADIAN_PER_SECOND;
			this->tauUnits(0) = ::rl::math::UNIT_NEWTON_METER;
		}
		
		Revolute::~Revolute()
		{
		}
		
		::rl::math::Real
		Revolute::distance(const ::rl::math::Vector& q1, const ::rl::math::Vector& q2) const
		{
			::rl::math::Real delta = ::std::abs(q2(0) - q1(0));
			
			if (this->wraparound(0))
			{
				::rl::math::Real range = ::std::abs(this->max(0) - this->min(0));
				return ::std::min(delta, ::std::abs(range - delta));
			}
			else
			{
				return delta;
			}
		}
		
		void
		Revolute::interpolate(const ::rl::math::Vector& q1, const ::rl::math::Vector& q2, const ::rl::math::Real& alpha, ::rl::math::Vector& q) const
		{
			if (this->wraparound(0))
			{
				::rl::math::Real diff = ::std::abs(q2(0) - q1(0));
				::rl::math::Real range = ::std::abs(this->max(0) - this->min(0));
				
				if (::std::abs(range - diff) < diff)
				{
					if (q1(0) > q2(0))
					{
						q(0) = (1.0f - alpha) * q1(0) + alpha * (q2(0) + range);
					}
					else
					{
						q(0) = (1.0f - alpha) * (q1(0) + range) + alpha * q2(0);
					}
					
					while (q(0) > this->max(0))
					{
						q(0) -= range;
					}
					
					while (q(0) < this->min(0))
					{
						q(0) += range;
					}
				}
				else
				{
					q(0) = (1.0f - alpha) * q1(0) + alpha * q2(0);
				}
			}
			else
			{
				q(0) = (1.0f - alpha) * q1(0) + alpha * q2(0);
			}
		}
		
		void
		Revolute::normalize(::rl::math::Vector& q) const
		{
			q(0) = ::std::fmod(q(0), 2.0f * static_cast< ::rl::math::Real>(M_PI));
			
			if (q(0) < this->min(0))
			{
				q(0) += 2.0f * static_cast< ::rl::math::Real>(M_PI);
			}
			else if (q(0) > this->max(0))
			{
				q(0) -= 2.0f * static_cast< ::rl::math::Real>(M_PI);
			}
		}
		
		void
		Revolute::setPosition(const ::rl::math::Vector& q)
		{
			this->q = q;
			this->t = ::rl::math::AngleAxis(this->q(0) + this->offset(0), this->S.block<3, 1>(0, 0));
			this->x.rotation() = this->t.linear().transpose();
		}
		
		::rl::math::Real
		Revolute::transformedDistance(const ::rl::math::Vector& q1, const ::rl::math::Vector& q2) const
		{
			::rl::math::Real delta = ::std::abs(q2(0) - q1(0));
			
			if (this->wraparound(0))
			{
				::rl::math::Real range = ::std::abs(this->max(0) - this->min(0));
				return ::std::pow(::std::min(delta, ::std::abs(range - delta)), 2);
			}
			else
			{
				return ::std::pow(delta, 2);
			}
		}
	}
}
