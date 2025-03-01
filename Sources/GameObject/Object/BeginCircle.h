#pragma once
#include "NormalObject.h"
class BeginCircle : public NormalObject {
public:

	BeginCircle(int number);

	void Update(Camera& camera) override;

private:

	int num_;
	int flame_;

};

