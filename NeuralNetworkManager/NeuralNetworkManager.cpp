#include "NeuralNetworkManager.h"


namespace
{
		//general configs fields names
		const char pathToNeuralNetworkName[] = "pathToNeuralNetwork";
		const char commandName[] = "command";

		const char* commands[] = {
						"save",
						"load",
						"create"
		};


		void saveNeuralNetwork(nnc_ns::NeuralNetworkShPtr i_network, const std::string& i_location)
		{

		}
		nnc_ns::NeuralNetworkShPtr loadNeuralNetwork(const std::string& i_location)
		{

		}
		nnc_ns::NeuralNetworkShPtr createNeuralNetwork(const Json::Value& i_config)
		{

		}
}

namespace nnm_ns
{
		std::map<NeuralNetworkManager::Command, std::string> NeuralNetworkManager::s_commandsString = {
						{SAVE, "save"},
						{LOAD, "load"},
						{CREATE, "create"}
		};

		NeuralNetworkManager::NeuralNetworkManager(const Json::Value &i_generalConfig)
		: d_pathToNeuralNetwork(i_generalConfig[pathToNeuralNetworkName].toString())
		{
			auto command = i_generalConfig[commandName].toString();
			for(const auto& [code, str] : s_commandsString)
			 if(str == command)
			 {
			  	d_command = code;
			  	break;
			 }

		}

		void NeuralNetworkManager::save()
		{

		}

		nnc_ns::NeuralNetworkUnPtr NeuralNetworkManager::load() {
		 return nnc_ns::NeuralNetworkUnPtr();
		}

		nnc_ns::NeuralNetworkUnPtr NeuralNetworkManager::create(const Json::Value &i_nnConfig) {
		 return nnc_ns::NeuralNetworkUnPtr();
		}
}