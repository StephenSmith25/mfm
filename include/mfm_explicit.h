#ifndef MFM_MFM_EXPLICIT_H_
#define MFM_MFM_EXPLICIT_H_


#include "mfm.h"
#include <memory.h>
#include "node.h"
#include "read_mesh.h"


namespace mfm{





//! MFMExplicit class
//! \brief A class that implements the fully explicit mfm
//! \details A single-phase explicit MPM
//! \tparam Tdim Dimension
template <unsigned Tdim>
class MFMExplicit : public MFM{


public:

	//! Default constructor
	MFMExplicit(std::unique_ptr<IO>&& io);

	//! Initialise mesh
	bool initialise_mesh() override;

	//! Intialise nodes
	bool initialise_nodes() override;

	//! Intialise Domain
	bool initialise_domain() override;



	//! Initialise particles
	bool initialise_particles() override;

	//! Solve 
	bool solve() override;


protected:
 	// Generate a unique id for the analysis
 	using mfm::MFM::uuid_;
  	//! Time step size
  	using mfm::MFM::dt_;
 	//! Current step
 	using mfm::MFM::step_;
 	//! Number of steps
	using mfm::MFM::nsteps_;
	//! Domain object
	std::unique_ptr<mfm::Domain<Tdim>> domain_;

	//! A unique ptr to IO object
	using mfm::MFM::io_;


	//! Material

private:

	//! Boolean to switch between UL and TL formulations
	bool UL_{false};

	//! AXISYMMETRIC
	bool AXI_{false};

};

#include "mfm_explicit.tcc"

}// end namespace






#endif