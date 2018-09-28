#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
	VectorXd rmse(4);
	rmse << 0,0,0,0;
    
    // TODO: YOUR CODE HERE

	// check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
	// ... your code here
	if(estimations.size() == 0){
	    cout<<"Error! The esitiomation vector size is zero!"<<endl;
	    return rmse;
	}
	else if(estimations.size() != ground_truth.size()){
	    cout<<"Error! The esitiomation vector size is different with the ground truth vector size!"<<endl;
	    return rmse;
	}
    
	//accumulate squared residuals
	for(int i=0; i < estimations.size(); ++i){
        // ... your code here
        rmse = rmse.array() + (estimations[i] - ground_truth[i]).array().square();
	}

	//calculate the mean
	// ... your code here
	//cout<<"estimations size is: "<<estimations.size()<<endl;// Added by Harrison
	rmse = rmse.array()/estimations.size();// The average should be calculated according to the data list size.!!!

	//calculate the squared root
	// ... your code here
	rmse = rmse.array().sqrt();

	//cout<<"rmse = "<<rmse<<endl;//Added by Harrison

	//return the result
	return rmse;
}