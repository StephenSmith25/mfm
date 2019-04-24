#ifndef MFM_MATERIAL_POINT_H_
#define MFM_MATERIAL_POINT_H_



//! Global index type for the cell
using Index = unsigned long long;

//! MaterialPoint
//! \brief Class that contains the material points of the meshfree problem
//! \tparam Tdim Dimension
template <unsigned Tdim>
class MaterialPoint
{
public:

	//! Default constructor 
	MaterialPoint();

	using VectorDim Eigen::Matrix<double, Tdim, 1);

	VectorDim reference_coordinates() const ;
	VectorDim update_coordinates();


private:
	VectorDim coords_;

	// Something about the material
	
	// Stressess
	double Sxx_, Syy_, Szz_;
	// Velocity

	// Displacemnets


	// Refrence position

	// Density

	// Reference desnity


};




#endif