#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <array>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include "particle_base.h"

namespace mfm {

//! Global index type for the particleBase
using Index = unsigned long long;

//! Particle class
//! \brief Base class that stores the information about particles
//! \details Particle class: id_ and coordinates.
//! \tparam Tdim Dimension
template <unsigned dim>
class Particle : public ParticleBase<dim>
{

  //! Define a vector of size dimension
  using VectorDim = Eigen::Matrix<double, dim, 1>;

  //! Define DOFs
  static const unsigned dof = (dim == 1) ? 1 : 3 * (dim - 1);


  //! Construct a particle with id, coordinates and status
  //! \param[in] id Particle id
  //! \param[in] coord coordinates of the particle
  Particle(Index id, const VectorDim& coord);



};




}



#endif 