// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDown/Enemy/BossSpawnActor.h"
#include "TopDown/Enemy/Enemy.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ABossSpawnActor::ABossSpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TorchValue = 1.f;
	CurrentTorchValue = 0.f;
}


void ABossSpawnActor::TorchActiveted() {
	UE_LOG(LogTemp, Warning, TEXT("SpawAciveted"));

	CurrentTorchValue++;
	if (CurrentTorchValue == TorchValue) {
		BossSpanw();
	}
}

void  ABossSpawnActor::AllEnemyStop() {
	TSubclassOf<AEnemy> ClassToFind;
	ClassToFind = AEnemy::StaticClass();
	TArray<AActor*> FoundActors;
	UE_LOG(LogTemp, Warning, TEXT("StopEnemyStart"));
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);
	for (auto& Enemy : FoundActors) {
		//if (Enemy->GetClass()->ImplementsInterface(UEnemyInterface::StaticClass())) {
			if (AEnemy* CurrEnemy = Cast<AEnemy>(Enemy)) {
				CurrEnemy->StopMove();
				UE_LOG(LogTemp, Warning, TEXT("StopEnemy"));
			}
		//}
	}
}
void  ABossSpawnActor::AllEnemyGo() {
	TSubclassOf<AEnemy> ClassToFind;
	ClassToFind = AEnemy::StaticClass();
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);
	for (int i = 0; i < FoundActors.Num(); i++) {
		//if (Enemy->GetClass()->ImplementsInterface(UEnemyInterface::StaticClass())) {
			if (AEnemy* CurrEnemy = Cast<AEnemy>(FoundActors[i])) {
				CurrEnemy->GoMove();
				UE_LOG(LogTemp, Warning, TEXT("GoEnemy"));
			}
		//}
	}
}
// Called when the game starts or when spawned
void ABossSpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABossSpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

