#ifndef NEURAL_NETWORKS_NEURAL_NETWORK_MANAGER_H
#define NEURAL_NETWORKS_NEURAL_NETWORK_MANAGER_H

#include <Common/Common.h>

#include <Json/Value.h>
#include <NeuralNetworksCollection/NeuralNetworksCollection.h>


namespace nnm_ns{

		class NeuralNetworkManager {
    public:
        explicit NeuralNetworkManager(const Json::Value& i_generalConfig);

				void save();
				nnc_ns::NeuralNetworkUnPtr load();
				nnc_ns::NeuralNetworkUnPtr create(const Json::Value& i_nnConfig);

    private:
				std::string d_pathToNeuralNetwork;
				enum  Command
				{
						SAVE,
						LOAD,
						CREATE,
						ERROR
				} d_command{ERROR};

				static std::map<Command, std::string> s_commandsString;
    };
}

#endif //NEURAL_NETWORKS_NEURAL_NETWORK_MANAGER_H
