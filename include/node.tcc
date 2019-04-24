//! Constructor with id, coordinates 
template <unsigned Tdim>
mfm::Node<Tdim>::Node(mfm::Index id, const VectorDim& coords)
{


	// Check if dimension is between 1 & 3 
	static_assert((Tdim >= 1 && Tdim <= 3), "Invalid global dimension");

	id_ = id;
	coordinates_ = coords;
	dof_ = Tdim;


	// clear any velocity constraints


}