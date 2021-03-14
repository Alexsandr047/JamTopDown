// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	DefaultHealth = 100.0f;

	Health = DefaultHealth;
}
void UHealthComponent::SetParams(float fHealth) {
	DefaultHealth = fHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* MyOwner = GetOwner();
	if (MyOwner) {
		MyOwner->OnTakePointDamage.AddDynamic(this, &UHealthComponent::HandleTakePointDamage);
	}
	
}
void UHealthComponent::HandleTakePointDamage(AActor* DamagedActor, float Damage, class AController* InstigatedBy, FVector HitLocation, class UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const class UDamageType* DamageType, AActor* DamageCauser) {
	if (Damage <= 0.0f || bIsDead) {
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
	bIsDead = Health <= 0.0f;
	UE_LOG(LogTemp, Log, TEXT("Health CHanget: %s"), *FString::SanitizeFloat(Health));
	OnHealthChanged.Broadcast(this, Health, Damage, BoneName, DamageType, InstigatedBy, DamageCauser);
}




