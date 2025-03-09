#pragma once

namespace EMapchip {

	enum ChipKind {

	};

	enum CollitionType {
		kAir,
		kBlock,
		kDamage,

		Type_Count
	};

}

class Chip {
public:

	Chip(EMapchip::ChipKind chipKind, EMapchip::CollitionType collitionType);
	~Chip() = default;

	EMapchip::ChipKind chipKind_;
	EMapchip::CollitionType collitionType_;
};

