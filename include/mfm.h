
#ifndef MFM_MPM_H_
#define MFM_MPM_H_

#include <chrono>
#include <memory>
#include <vector>
#include "io.h"
#include "domain.h"

namespace mfm {



	//! MFM class
	//! \brif MFM class calls solver and algorithm
	//! \details mfm class: implicit and explicit mfm
	class MFM{
	public:

		MFM(std::unique_ptr<IO>&& io) : io_(std::move(io)){

		}

  		// Initialise mesh and particles
  		virtual bool initialise_mesh() = 0;

  		// Initialise particles
		virtual bool initialise_particles() = 0;

		//! Intialise nodes
		virtual bool initialise_nodes() = 0;

		//! Initialise domain
		virtual bool initialise_domain() = 0;

		// Solve
		virtual bool solve() = 0;

	protected:

		//! Unique id for the problem
		std::string uuid_;

		//! Time step size
		double dt_{std::numeric_limits<double>::max()};
		
		//! If the formulation is axisymmetric 
		bool axi_{false};

		//! Current step
		mfm::Index step_{0};

		//! Number of steps
		mfm::Index nsteps_{std::numeric_limits<mfm::Index>::max()};
  		
  		//! A unique ptr to IO object
		std::unique_ptr<mfm::IO> io_;

	};

}// end namspace MFM










#endif // MFM_MPM_H_