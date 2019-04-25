//! Return shape fucntins of a 3 node trianglular element at a given local coordinate
template <>
inline Eigen::VectorXd mfm::TriangularElement<2>::shape_fn(
	const Eigen::Matrix<double,2,1>& xi) const
{

	Eigen::Matrix<double,3,1> shapefn;

	shapefn(0) = 1;
	shapefn(1) = 1;
	shapefn(2) = 3;

	return shapefn;
}

//! Return gradient of shape functions at a particular point in the local coordinates
template <>
inline Eigen::MatrixXd mfm::TriangularElement<2>::grad_shapefn(
	const Eigen::Matrix<double,2,1>& xi) const
{

	Eigen::Matrix<double,3,2> grad_shapefn;






	return grad_shapefn;


}