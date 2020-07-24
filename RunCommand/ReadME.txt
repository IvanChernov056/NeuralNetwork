/**

       Project: RunCommand
       Description: Contains main() function. Implements the following commands:
        1)Generate and train network: By given json finds location of dataset,
          calls NNManager to construct new network, runs training and saves this network in given in json location by
          calling NNManager's functionality.
          The trained neural network is used in test system.
        2)Load already trained existing network, run in on given data and saves result without comparing it with
          any etalon.


*/