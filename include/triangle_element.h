#ifndef MFM_TRIANGLE_ELEMENT_H
#define MFM_TRIANGLE_ELEMENT_H



#include "element.h"


//! MFM namespace
namespace mfm{

//! Global index type for the cell
using Index = unsigned long long;


//! Triangle element class derived from Element class
//! \brief triangular element
//! \details 3-noded\n
//! Shape function, gradient shape function \n
//! 3-node Triangular Element \n
//! <pre>
//!			1
//!        / \
//!       /   \
//!      /     \
//!     /       \
//!    /         \
//! 0 0----------0 2
//!
//! </pre>


//! \tparam Tdim Dimension
template <unsigned Tdim>
class TriangularElement : public Element<Tdim>{

public:


  	//! Define a vector of size dimension
	using VectorDim = Eigen::Matrix<double, Tdim, 1>;
	
	//! Constructor
	TriangularElement(const std::vector<VectorDim> verticies) : mfm::Element<Tdim>()
	{
	static_assert(Tdim == 2, "Invalid dimension for a triangular element");
	this->verticies_ = verticies;
	}

	//! Return quadrature of the element in local coordinates.
	std::shared_ptr<mfm::Quadrature<Tdim>> quadratures(unsigned order) override;

  	//! Evaluate local shape functions at given coordinates
 	//! \param[in] xi given local coordinates
 	//! \retval shapefn Shape function of a given cell
 	Eigen::VectorXd shapefn(const VectorDim& xi) const override;


	//! Evaluate gradient of shape functions
 	//! \param[in] xi given local coordinates
  	//! \retval grad_shapefn Gradient of shape function of a given cell
    Eigen::MatrixXd grad_shapefn(
      const VectorDim& xi) const override;


};














}



#endif