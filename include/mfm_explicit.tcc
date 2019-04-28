//! Constructor
template <unsigned Tdim>
mfm::MFMExplicit<Tdim>::MFMExplicit(std::unique_ptr<IO>&& io) : mfm::MFM(std::move(io))
{

	std::cout << "in constructor for mfm " << std::endl;

	// set analysis step to start at 0
	this->step_ = 0;


	// Create a domain with global id 0
	const mfm::Index id = 0;	
	domain_ = std::make_unique<mfm::Domain<Tdim>>(id);
	// Json stuff

}
// Initialise nodes
template<unsigned Tdim>
bool mfm::MFMExplicit<Tdim>::initialise_nodes()
{


	bool status = true;
	// create a mesh reader
	auto mesh_reader = std::make_shared<ReadMesh<Tdim>>(this->io_->get_mesh_file_name());


	// Global Index
	mfm::Index gid = 0;

	bool check_duplicate = false;

	// create nodes from file
	domain_->create_nodes(gid,
	mesh_reader->read_nodes(),
	check_duplicate);




	// Read cells which match the given ID
	auto cells = mesh_reader->read_mesh_cells(4);

	for ( const auto & cell_ : cells)
	{

		for ( auto i = cell_.begin() ; i != cell_.end(); ++i)
		{
		std::cout << *i << ",";

		}
		std::cout << std::endl;
	}


	// We can now read mesh_cells



	// we probably need to create a mesh 



	// If they are blockset use the celsl to generate material points
	//domain_->generate_material_points(cells,quad_points)




	// read velocity constraint nodes with ID_1
	// create_velocity constraint ( mesh_reader->read_velocity(ID), std::array<2> {DOF and DOUBLE })


	// CREATING MATERIAL POINTS WILL BE A PAIN
	 // - A HUGE PAIN}


	return status;
}


template <unsigned Tdim>
bool mfm::MFMExplicit<Tdim>::initialise_mesh()
{


	bool status = true;

	auto mesh_reader = std::make_shared<ReadMesh<Tdim>>(this->io_->get_mesh_file_name());


	// Read elemnets
	auto nodal_coords = mesh_reader->read_nodes();
	auto cells = mesh_reader->read_mesh_cells(4);

	// read velocity constraints
	std::cout << "got out " << std::endl;



	// print coordinates out
	unsigned ID_MESH = 1;
	auto mesh_ = std::make_unique<Mesh<Tdim>>(ID_MESH);


	// SO ive read the cells, I need to make the mesh to make the elements to make the material poitns
	// I need to deal with the physcial groups
	// I need to do a few other things to get it working
	// I need to handle the json file.
	// Am I going to continue pushign down this visual studio route, or am i going to move on to 
	// trying to get linxu working on this laptop
	// Maybe I can try docker.







	// read pressure boundary conditions


	return status;
}

// Initialise mesh (not sure if we need this)
// We need a mesh to find nodal locations
// Place quadrature points
// Read in where velocity constraints are placed
// - Read in velocity constraints
// - Read in Pressure boundaries
// - Read in nodal tractions?
// - Read in domain elements ( WHATS THE NAME FOR THIS?) 
// But this is a disposable mesh, so we dont need to store it....

template <unsigned Tdim>
bool mfm::MFMExplicit<Tdim>::initialise_domain()
{
	bool status = true;
	auto mesh_reader = std::make_shared<ReadMesh<Tdim>>(this->io_->get_mesh_file_name());

	// using the mesh reader we can get the nodes


	std::string element_type;


	// We can then get the elements


	// Read blocksets, with ID id_ and eType e_type;
		// prototype read_mesh_elements


	// now create material points based on thsoe elements



	// we can then get any velocity constraints


	// we can then get traction and pressure loads

	return false;
}

template <unsigned Tdim>
bool mfm::MFMExplicit<Tdim>::initialise_particles()
{




	return false;
}

template <unsigned Tdim>
bool mfm::MFMExplicit<Tdim>::solve()
{


	this->initialise_nodes();
	this->initialise_mesh();


	return false;
}