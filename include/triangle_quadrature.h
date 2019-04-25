#ifndef MFM_TRIANGLE_QUADRATURE_H_
#define MFM_TRIANGLE_QUADRATURE_H_

#include <exception>
#include <eigen3/Eigen/Dense>

#include "quadrature.h"

//! mfm Namespace

namespace mfm{


// Triangle quadrature class derived from Quadrature base class
//! \brief quadrature (gauss points) for a triangular  element
//! \tparam Tdim Dimension
//! \tparam Torder Order of quadrature scheme

template <unsigned Tdim, unsigned Torder>
	class TriangleQuadrature : public Quadrature<Tdim>
	{

		static_assert(Tdim == 2, "Invalid dimension for triangular element");

	
	//! Return quadrature points
	//! \param[out] qpoints Quadrature points in local coordinates
	Eigen::MatrixXd quadratures() const override;
	
	//! Return weights
	//! \param[out] weights for quadrature points
	Eigen::VectorXd weights() const override;

	};

}//! End namespace 





#endif 