#ifndef MFM_BLOCKSET_H_
#define MFM_BLOCKSET_H_

#include <eigen3/Eigen/Dense>
#include <vector>
namespace mfm {

template <unsigned Tdim> class Blockset {

  //! Define a vector of size dimension
  using VectorDim = Eigen::Matrix<double, Tdim, 1>;

private:
  std::vector<typename _Tp>
};

} // namespace mfm

#endif