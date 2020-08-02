//
// Created by boku on 25.07.2020.
//

#ifndef NEURAL_NETWORKS_NEURAL_NETWORKS_COLLECTION_H
#define NEURAL_NETWORKS_NEURAL_NETWORKS_COLLECTION_H

namespace nnc_ns {
		class NeuralNetwork {

		};

		using NeuralNetworkUnPtr = std::unique_ptr<NeuralNetwork>;
		using NeuralNetworkShPtr = std::shared_ptr<NeuralNetwork>;
}

#endif //NEURAL_NETWORKS_NEURAL_NETWORKS_COLLECTION_H
