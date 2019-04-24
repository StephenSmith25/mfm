#ifndef MFM_ELEMENT_H_
#define MFM_ELEMENT_H_

#include <exception>
#include <map>
#include <memory>
#include <vector>
#include <eigen3/Eigen/Dense>

#include "quadrature.h"



namespace mfm
{



//! Base class of shape functions
//! \brief Base class that stores the information about shape functions
//! \tparam Tdim Dimension

template <unsigned dim>
	class Element{


   	//! Define a vector of size dimension
	using VectorDim = Eigen::Matrix<double, dim, 1>;


  	//! Constructor
  	//! Assign variables to zero
  	Element() = default;

  	//! Destructor
  	virtual ~Element() {}


  	//! Return quadrature of the element
 	virtual std::shared_ptr<mfm::Quadrature<dim>> quadrature(
	unsigned nquadratures) const = 0;



	};









}







#endif