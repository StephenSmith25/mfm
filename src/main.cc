#include <iostream>
#include <vector>
#include "particle.h"
#include <eigen3/Eigen/Dense>
#include "read_mesh.h"
#include "io.h"
#include <memory>
#include "mfm_explicit.h"




using Index = unsigned long long;

int main(int argc, char ** argv)
{
	// Problem dimensions
	const int dim = 2;

	// Problem vector sizes
	using VectorDim = Eigen::Matrix<double, dim, 1>;

	// create an IO object
	auto io = std::make_unique<mfm::IO>(argc,argv);


	// TEST FILENAME 
	const std::string filename = "test.msh";
	const std::string json_name = "test.json";

	

	io->set_mesh_file_name(filename);


	// Create an mfm anaylsis
	auto mfm = std::make_unique<mfm::MFMExplicit<dim>>(std::move(io));

	
	mfm->solve();

	// Mesh should contain all the nodes and elements, and subsequently the material points

	// Material points created and then mesh is destroyed

	// mfm::ReadMesh<dim> mesh(filename);
	// // read_nodes
	// std::vector<VectorDim> nodal_coordinates = mesh.read_nodes();


	// Create a domain




	// Now create the particles
	 // For each particle coordinate create a particle 
	//auto io = std::make_unique<mfm::IO>(argc, argv);
	// To interpolate the field at each particle a MLS or MAXENT shape function is used 

	// So the particles are used to interpolate the field u(x) and delta_u (x)

	// Now enter the meshfree class


	// Now create the material points
		// this is where stress is sampled, integrals are formed, density and material state is stored here.




	system("pause");

	return 0;
}