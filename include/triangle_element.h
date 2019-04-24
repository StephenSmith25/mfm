#ifndef MFM_TRIANGLE_ELEMENT_H
#define MFM_TRIANGLE_ELEMENT_H



#include "element.h"


//! MFM namespace
namespace mfm{



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
	TriangularElement() : mfm::Element<Tdim>()
	{
	static_assert(Tdim == 2, "Invalid dimension for a triangular element");
	}

};














}



#endif