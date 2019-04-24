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




	mesh_reader->read_mesh_cells(1);


	return status;
}


template <unsigned Tdim>
bool mfm::MFMExplicit<Tdim>::initialise_mesh()
{


	bool status = true;

	auto mesh_reader = std::make_shared<ReadMesh<Tdim>>(this->io_->get_mesh_file_name());


	// Read elemnets


	// read velocity constraints


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
	//this->initialise_mesh();


	return false;
}