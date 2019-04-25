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
			const int id)
{

	// Mesh cells
	std::vector<std::vector<mfm::Index>> cells ;
	cells.clear();



	//  Cell type
	int celltype;

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
						bool newCell = false;


						while(line.compare(elementsEnd) != 0)
						{

							// Boolean of whether a new cell was added
							newCell = false;


							cell.clear();

							// Trim the line
							boost::algorithm::trim(line);
							std::istringstream istream(line);

							// Split each line into tokens serpated by a space 
							std::vector<std::string> tokens;
							boost::split(tokens,line,boost::is_any_of(" ")); 

							// First entry is node number

							celltype = std::stoi(tokens.at(1));



							cellID = std::stoi(tokens.at(3));
				
							//std::cout << tokens.at(1) << std::endl;	
							if ( cellID == id){

								newCell = true;


								// line elemnt
								if ( celltype == 1){
								for ( unsigned i = 0 ; i < 2 ; ++i)
									{
										cell.emplace_back(std::stoll(tokens.at(5+i)) -1 );
									}
								}
								// triangular element 
								if ( celltype == 2){
									for ( unsigned i = 0 ; i < 3 ; ++i)
									{
									cell.emplace_back(std::stoll(tokens.at(5+i)) -1 );
									}
								}
								// quad
								if ( celltype == 3){
								for ( unsigned i = 0 ; i < 4 ; ++i)
									{
										cell.emplace_back(std::stoll(tokens.at(5+i)) -1 );
									}
								}

								// tet
								if ( celltype == 4){
								for ( unsigned i = 0 ; i < 4 ; ++i)
									{
										cell.emplace_back(std::stoll(tokens.at(5+i)) -1 );
									}

								}


							}

							//  If a new cell was genrated add it to the list
							if ( newCell) cells.emplace_back(cell);
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