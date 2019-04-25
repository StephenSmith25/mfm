// Getting quadrature for Torder = 1
template <>
inline Eigen::MatrixXd mfm::TriangleQuadrature<2,1>::get_local_quadratures() const{
	Eigen::Matrix<double,2,1> quadratures;
	quadratures(0,0) = 0.25;
	quadratures(1,0) = 0.25;

	return quadratures;
}
// Getting weights for order = 1
template<>
inline Eigen::VectorXd mfm::TriangleQuadrature<2,1>::weights() const
{
	Eigen::VectorXd weights(1);
	weights(0) = 1;
}