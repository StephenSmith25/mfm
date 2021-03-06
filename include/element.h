#ifndef MFM_ELEMENT_H_
#define MFM_ELEMENT_H_

#include <eigen3/Eigen/Dense>
#include <exception>
#include <map>
#include <memory>
#include <vector>

#include "quadrature.h"

namespace mfm {

enum ElementTypes {
  line = 1,
  triangular = 2,
  quadrilateral = 3,
  tetrahedral = 4,
};

//! Base class of element
//! \brief Base class that stores the information about element properties:
//! quadrature and shape functions \tparam Tdim Dimension

template <unsigned dim> class Element {

  //! Define a vector of size dimension
  using VectorDim = Eigen::Matrix<double, dim, 1>;

  //! Constructor
  //! Assign variables to zero
  Element() = default;

  //! Destructor
  virtual ~Element() {}

  //! Return quadrature of the element
  virtual std::shared_ptr<mfm::Quadrature<dim>>
  quadrature(unsigned nquadratures) const = 0;

  //! Evaluate local shape functions at given coordinates
  //! \param[in] xi given local coordinates
  //! \retval shapefn Shape function of a given cell
  virtual Eigen::VectorXd shapefn(const VectorDim &xi) const = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  //! \retval grad_shapefn Gradient of shape function of a given cell
  virtual Eigen::MatrixXd grad_shapefn(const VectorDim &xi) const = 0;
};

} // namespace mfm

#endif