#ifndef MFM_QUADRATURE_H_
#define MFM_QUADRATURE_H_


#include <algorithm>
#include <limits>
#include <vector>

#include <eigen3/Eigen/Dense>


//! MFM namespace
namespace mfm {




template<unsigned dim>

	class Quadrature
	{

		//! Default constructor
		Quadrature() = default;


		//! Destructor
		virtual ~Quadrature() {}

		//! Return quadrature points
  		//! \param[out] qpoints Quadrature points in local coordinates
  		virtual Eigen::MatrixXd quadratures() const = 0;

  		//! Return weights
  		//! \param[out] weights Weights for quadrature points
		virtual Eigen::VectorXd weights() const = 0;


	};

}//! end name space


#endif 