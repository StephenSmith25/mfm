#ifndef READ_MESH_H_
#define READ_MESH_H_

#include <array>
#include <exception>
#include <fstream>
#include <memory>
#include <tuple>
#include <vector>
#include "eigen3/Eigen/Dense"
#include "boost/algorithm/string.hpp"
#include "boost/foreach.hpp"
#include "boost/tokenizer.hpp"



namespace mfm {

	//! Global index type for the cell
	using Index = unsigned long long;

	//! ReadMesh class
	//! \brief Class that returns mesh and particles locataions based on GMesh ascii file 
	//! \tparam Tdim Dimension
	template <unsigned Tdim>
	class ReadMesh {
	public:


		//! Define a vector of size dimension 
		using VectorDim = Eigen::Matrix<double, Tdim, 1>;

		//! Constructor
		ReadMesh(){
		};


		//! Constructor with filename
		//! \param[in] filename with name of file
		ReadMesh(std::string filename)
		{
			//! filename_
			filename_ = filename;
		}


		//! Read mesh elements of a particular id
		//! \param[in] mesh ID within gmesh file
		//! \retval cells Vector of nodal indices of cells
		std::vector<std::vector<mfm::Index>> read_mesh_cells(
			const int id );



		//! Read nodes from mesh file filename_
		//! \retval coordinates Vector of nodal coordinates
		std::vector<VectorDim> read_nodes();


		//! read nodal velocity constraints
		//! \retval tuple of <nodal Index, degree of freedom (x,y,z), constraint>
		std::tuple<mfm::Index, unsigned , double > read_velocity_constraints();

	private:
		std::string filename_;
	};


#include "read_mesh.tcc"

}


#endif 