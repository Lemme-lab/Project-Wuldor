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

#ifndef RL_MATH_PLUECKERTRANSFORM_H
#define RL_MATH_PLUECKERTRANSFORM_H

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace rl
{
	namespace math
	{
		/**
		 * Spatial vector algebra.
		 * 
		 * Roy Featherstone. Rigid Body Dynamics Algorithms. Springer, New
		 * York, NY, USA, 2008.
		 */
		namespace spatial
		{
			template<typename Scalar> class ArticulatedBodyInertia;
			template<typename Scalar> class ForceVector;
			template<typename Scalar> class MotionVector;
			template<typename Scalar> class RigidBodyInertia;
			
			/**
			 * Pl&uuml;cker transform.
			 */
			template<typename Scalar>
			class PlueckerTransform
			{
			public:
				EIGEN_MAKE_ALIGNED_OPERATOR_NEW
				
				typedef Scalar ScalarType;
				
				typedef ::Eigen::Matrix<Scalar, 6, 6> MatrixType;
				
				typedef ::Eigen::Matrix<Scalar, 3, 3> RotationType;
				
				typedef const RotationType ConstRotationType;
				
				typedef ::Eigen::Transform<Scalar, 3, ::Eigen::Affine> TransformType;
				
				typedef ::Eigen::Matrix<Scalar, 3, 1> TranslationType;
				
				typedef const TranslationType ConstTranslationType;
				
				PlueckerTransform()
				{
				}
				
				virtual ~PlueckerTransform()
				{
				}
				
				PlueckerTransform inverse() const
				{
					PlueckerTransform res;
					res.rotation() = rotation().transpose();
					res.translation() = -rotation() * translation();
					return res;
				}
				
				MatrixType inverseForce() const
				{
					MatrixType res;
					res.template topLeftCorner<3, 3>() = rotation().transpose();
					res.template topRightCorner<3, 3>() = translation().cross33() * rotation().transpose();
					res.template bottomLeftCorner<3, 3>().setZero();
					res.template bottomRightCorner<3, 3>() = rotation().transpose();
					return res;
				}
				
				MatrixType inverseMotion() const
				{
					MatrixType res;
					res.template topLeftCorner<3, 3>() = rotation().transpose();
					res.template topRightCorner<3, 3>().setZero();
					res.template bottomLeftCorner<3, 3>() = translation().cross33() * rotation().transpose();
					res.template bottomRightCorner<3, 3>() = rotation().transpose();
					return res;
				}
				
				MatrixType matrixForce() const
				{
					MatrixType res;
					res.template topLeftCorner<3, 3>() = rotation();
					res.template topRightCorner<3, 3>() = -rotation() * translation().cross33();
					res.template bottomLeftCorner<3, 3>().setZero();
					res.template bottomRightCorner<3, 3>() = rotation();
					return res;
				}
				
				MatrixType matrixMotion() const
				{
					MatrixType res;
					res.template topLeftCorner<3, 3>() = rotation();
					res.template topRightCorner<3, 3>().setZero();
					res.template bottomLeftCorner<3, 3>() = -rotation() * translation().cross33();
					res.template bottomRightCorner<3, 3>() = rotation();
					return res;
				}
				
				template<typename OtherScalar>
				ForceVector<OtherScalar> operator*(const ForceVector<OtherScalar>& other) const;
				
				template<typename OtherScalar>
				MotionVector<OtherScalar> operator*(const MotionVector<OtherScalar>& other) const;
				
				PlueckerTransform operator*(const PlueckerTransform& other) const
				{
					PlueckerTransform res;
					res.rotation() = rotation() * other.rotation();
					res.translation() = other.translation() + other.rotation().transpose() * translation();
					return res;
				}
				
				template<typename OtherScalar>
				RigidBodyInertia<OtherScalar> operator*(const RigidBodyInertia<OtherScalar>& other) const;
				
				template<typename OtherScalar>
				ArticulatedBodyInertia<OtherScalar> operator*(const ArticulatedBodyInertia<OtherScalar>& other) const;
				
				template<typename OtherScalar>
				ForceVector<OtherScalar> operator/(const ForceVector<OtherScalar>& other) const;
				
				template<typename OtherScalar>
				MotionVector<OtherScalar> operator/(const MotionVector<OtherScalar>& other) const;
				
				template<typename OtherScalar>
				RigidBodyInertia<OtherScalar> operator/(const RigidBodyInertia<OtherScalar>& other) const;
				
				template<typename OtherScalar>
				ArticulatedBodyInertia<OtherScalar> operator/(const ArticulatedBodyInertia<OtherScalar>& other) const;
				
				RotationType& rotation()
				{
					return rotationData;
				}
				
				ConstRotationType& rotation() const
				{
					return rotationData;
				}
				
				void setIdentity()
				{
					rotation().setIdentity();
					translation().setZero();
				}
				
				TransformType transform() const
				{
					TransformType res;
					res.linear() = rotation();
					res.translation() = -rotation() * translation();
					return res;
				}
				
				TranslationType& translation()
				{
					return translationData;
				}
				
				ConstTranslationType& translation() const
				{
					return translationData;
				}
				
			protected:
				
			private:
				RotationType rotationData;
				
				TranslationType translationData;
			};
		}
	}
}

#endif // RL_MATH_PLUECKERTRANSFORM_H
