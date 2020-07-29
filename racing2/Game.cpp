#include "Game.h"
#include <memory>
Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}

	//Entities is built over a multimap, it enable flow like access, it should implement immutable access
	EntityManager::getInstance().Entities;
	EntityManager::getInstance().Entities.emplace(Entity::EntityType::Player, std::shared_ptr<Entity::Entity>(new Player(renderer)));
	EntityManager::getInstance().Entities.emplace(Entity::EntityType::Terrain, std::shared_ptr<Entity::Entity>(new Road(renderer)));
	EntityManager::getInstance().Entities.emplace(Entity::EntityType::Camera, std::shared_ptr<Entity::Entity>(new Camera(renderer, width, height)));
	auto camera = EntityManager::getInstance().GetSingle<Camera>(Entity::EntityType::Camera);
	auto player = EntityManager::getInstance().GetSingle<Player>(Entity::EntityType::Player);
	auto road = EntityManager::getInstance().GetSingle<Road>(Entity::EntityType::Terrain);
	camera->follow(player, 20, 20);
	for (auto& entity : EntityManager::getInstance().Entities) {
		std::cout << (entity.second->texture) << "/n";
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
	else {
		Keyboard::getInstance().handleEvents(event);	
	}
}

void Game::update(std::chrono::microseconds delta)
{
	double t = delta.count() / 10000.0;
	EntityManager::getInstance().Update(t);
	
}

void Game::render()
{
	auto camera = EntityManager::getInstance().GetSingle<Camera>(Entity::EntityType::Camera);
	SDL_RenderClear(renderer);
	for (auto& entity : EntityManager::getInstance().Entities) {
		SDL_Rect rect;
		auto a = entity.second;
		camera->getRenderPosition(entity.second, &rect);
		SDL_RenderCopy(renderer, entity.second->texture, NULL, &rect);
	}
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}