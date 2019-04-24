#ifndef PARTICLE_BASE_H_
#define PARTICLE_BASE_H_
#include <array>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <eigen3/Eigen/Dense>



namespace mfm {


//Forward decleration of material class 
template <unsigned dim>
class Material;

//! Global index type for the particleBase
using Index = unsigned long long;

//! ParticleBase class
//! \brief Base class that stores the information about particleBases
//! \details ParticleBase class: id_ and coordinates.
//! \tparam Tdim Dimension
template <unsigned Tdim>
class ParticleBase{
public:

	 //! Define a vector of size dimension
	using VectorDim = Eigen::Matrix<double,Tdim,1>;

	//! Constructor with id and coordinates
 	//! \param[in] id Particle id
	//! \param[in] coord coordinates of the particle
	ParticleBase(Index id, const VectorDim& coord);

	//! Destructor 
	virtual ~ParticleBase(){};

	//! Return id of the particleBase
	Index id() const { return id_; }

	//! Assign coordinates
 	//! \param[in] coord Assign coord as coordinates of the particleBase
	void assign_coordinates(const VectorDim& coord) { coordinates_ = coord; }

	protected:
		//! coordinates
		VectorDim coordinates_;
		//! particleBase iD
		Index id_;
		//! Cell id
		int cell_id;

		//! Reference coordinates (in a cell)
		Eigen::Matrix<double,Tdim,1> xi_;

	};





}



#include "particle_base.tcc"








#endif // MFM_PARTICLEBASE_H__