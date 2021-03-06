#include "domain.h"

//! Constructor
template <unsigned Tdim>
mfm::Domain<Tdim>::Domain(unsigned id )
{

	this->id_ = id;
	nodes_.clear();

}

//! Create nodes from coordinates
template <unsigned Tdim>
bool mfm::Domain<Tdim>::create_nodes(mfm::Index gnid,
	const std::vector<VectorDim>&  coordinates,
	bool check_duplicate)
{


	if ( coordinates.empty())
 		throw std::runtime_error("List of coordinates is empty");

 	for ( const auto& node_coordinates : coordinates)
 	{
 		// add the node to domain
 		bool insert_status = this->add_node(
 		//create a node
 		std::make_shared<Node<Tdim>>(gnid, node_coordinates));
 		if ( insert_status ) ++gnid;
 	}
	return false;
}

//! Add a node to the domain
template <unsigned Tdim>
bool mfm::Domain<Tdim>::add_node(const std::shared_ptr<mfm::Node<Tdim> > &node,
								 bool check_duplicates){
	// Add node to vector 
	this->nodes_.push_back(node);


	return false;

}

template <unsigned Tdim>
std::vector<typename mfm::Domain<Tdim>::VectorDim> mfm::Domain<Tdim>::nodal_coordinates() const
{
	std::vector<VectorDim> nodalCoords;
	nodalCoords.reserve(this->nnodes());


	for (const auto& node : nodes_)
	{
		nodalCoords.emplace_back(node->coordinates());
	}

	return nodalCoords;

};
