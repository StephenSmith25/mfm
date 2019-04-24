template <unsigned Tdim>
std::vector<Eigen::Matrix<double,Tdim,1>> mfm::ReadMesh<Tdim>::read_nodes()
{

	// Particle coordinates
	std::vector<VectorDim> coordinates;
	coordinates.clear();

	// Expected number of particles
	mfm::Index nparticles;



	// input file stream
	std::fstream file;
	file.open(this->filename_, std::ios::in);

	std::string nodesStart("$Nodes");
	std::string nodesEnd("$EndNodes");


	try {
		if (file.is_open() && file.good()) {
			// line
			std::string line;
			// input stream class to operate on strings
			std::istringstream istream(line);
			
			// iterate over lines
			while (std::getline(file, line))
			{
				// trim the line 
				boost::algorithm::trim(line);
				// ignore commnet lines (#) and blank lines
				if ((line.find('#') == std::string::npos) && (line != ""))
				{

					// Find nodes line
					if (line.compare(nodesStart) == 0)
					{
						std::getline(file, line);
						// Trim the line
						boost::algorithm::trim(line);
						// First entry will contain the number of nodes
						nparticles = std::stoi(line);

						// Coordinates of each particle 
						Eigen::Matrix<double, Tdim, 1> coords;

						std::getline(file, line);
						// Trim the line
						boost::algorithm::trim(line);

						while(line.compare(nodesEnd) != 0)
						{

							// Trim the line
							boost::algorithm::trim(line);

							std::istringstream istream(line);

							// Coordinates
							Eigen::Matrix<double, Tdim, 1> coords;

							// Have to skip the first entry as it is the node number;
							istream >> coords[0];

							// Create each coordinate  
							for (unsigned i = 0; i < Tdim; ++i)
							{
								istream >> coords[i];

							}

							// Add new coordinate to coordinates vector  
							coordinates.emplace_back(coords);


							// Get new line
							std::getline(file, line);
							// Trim the line
							boost::algorithm::trim(line);

						
						}

					}
				}

			}
		}

		file.close();
	}catch (std::exception& exception) {

		file.close();

	}



	return coordinates;




}



//! Read mesh elements of a particular id
template <unsigned Tdim>
std::vector<std::vector<mfm::Index>> mfm::ReadMesh<Tdim>::read_mesh_cells(
			const mfm::Index id)
{

	// Mesh cells
	std::vector<std::vector<mfm::Index>> cells ;
	cells.clear();



	//  Cell type
	int cellType = -1;

	// cell id
	int cellID = -1;



	// input file stream
	std::fstream file;
	file.open(this->filename_, std::ios::in);

	std::string elementsStart("$Elements");
	std::string elementsEnd("$EndElements");





	try {
		if (file.is_open() && file.good()) {
			// line
			std::string line;
			// input stream class to operate on strings
			std::istringstream istream(line);
			std::cout << line << std::endl;
			// iterate over lines
			while (std::getline(file, line))
			{
				// trim the line 
				boost::algorithm::trim(line);
				// ignore commnet lines (#) and blank lines
				if ((line.find('#') == std::string::npos) && (line != ""))
				{

					// Find nodes line
					if (line.compare(elementsStart) == 0)
					{
						std::getline(file, line);
						// Trim the line
						boost::algorithm::trim(line);
						// indicies of each cell 
						std::vector<mfm::Index> cell;

						std::getline(file, line);
						// Trim the line
						boost::algorithm::trim(line);

						while(line.compare(elementsEnd) != 0)
						{

							// Trim the line
							boost::algorithm::trim(line);
							std::istringstream istream(line);

							// check id matches
							// if so then add to 

							std::cout << line << std::endl;

				
							// Get new line
							std::getline(file, line);
							// Trim the line
							boost::algorithm::trim(line);

						
						}

					}
				}

			}
		}

		file.close();
	}catch (std::exception& exception) {

		file.close();

	}


	return cells;

}