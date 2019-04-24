//! Constructor with id and coordinates
template <unsigned Tdim>
mfm::ParticleBase<Tdim>::ParticleBase(Index id, const VectorDim& coord)
	: id_{ id } {
	// Check if the dimension is between 1 & 3
	static_assert((Tdim >= 1 && Tdim <= 3), "Invalid global dimension");
	coordinates_ = coord;
}
