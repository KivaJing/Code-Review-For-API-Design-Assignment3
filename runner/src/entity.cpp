#include "entity.h"

void SingleEntity::Move(float m_deltatime)
{
    entity.rect.left += m_deltatime * entity.m_Speed.x;
    if (entity.rect.left + entity.rect.width < 0)
    {
        entity.rect.left = screen_width;
    }
}

void SingleEntity::Update(float m_deltatime)
{
    Move(m_deltatime);
}

void SingleEntity::Render(runner::PrimitiveBatch& batch) const
{
    if (entity.is_hollow)
    {
        batch.draw_rectangle(entity.rect, entity.thickness, entity.color);
    }
    else
    {
        batch.draw_rectangle(entity.rect, entity.color);
    }
}

void EntityManager::AddEntity(const Rect_entity& entity)
{
    entity_list.emplace_back(entity);
}

void EntityManager::ClearEntities()
{
    entity_list.clear();
}

void EntityManager::UpdateEntities(float m_deltatime)
{
    for (auto& entity : entity_list)
    {
        entity.Update(m_deltatime);
    }
}

void EntityManager::RenderEntities(runner::PrimitiveBatch& batch)
{
    for (const auto& entity : entity_list)
    {
        entity.Render(batch);
    }
}
