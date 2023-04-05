// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{

	Health = 100;
	HealthMax = 100;
}


bool USAttributeComponent::ApplyHealthChange(float Delta) {

	//Manter vida entre 0 e HealthMax
	if (Health + Delta >= 0 && Health + Delta <= HealthMax) {
		Health += Delta;
	}
	
	OnHealthChanged.Broadcast(nullptr, this, Health, Delta, HealthMax);

	return true;

}


bool USAttributeComponent::IsAlive() const {
	
	return Health > 0.0f;

}