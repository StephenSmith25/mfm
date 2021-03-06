#ifndef MFM_IO_H_
#define MFM_IO_H_

#include <fstream>
#include <memory>
#include <string>

namespace mfm {

//! \brief Input/Output handler
class IO {
public:
  //! Constructor with argc and argv
  //! \param[in] argc Number of input arguments
  //! \param[in] argv Input arguments
  IO(int argc, char **argv){

  };

  //! Return number of tbb threads
  unsigned nthreads() const { return nthreads_; }

  //! Sets the mesh file name
  void set_mesh_file_name(std::string filename) {
    this->input_file_ = filename;
  }

  //! Returns the mesh file name
  std::string get_mesh_file_name() const { return input_file_; }

private:
  unsigned nthreads_{0};

  //! Input file name
  std::string input_file_{"mfm.mesh"};
};

} // namespace mfm

#endif