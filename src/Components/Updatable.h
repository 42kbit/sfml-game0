#pragma once
class Updatable {
public:
	Updatable();
	~Updatable();

	virtual void on_update() = 0;
};