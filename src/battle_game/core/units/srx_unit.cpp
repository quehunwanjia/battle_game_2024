#include "srx_unit.h"
#include "battle_game/core/bullets/bullets.h"
#include "battle_game/core/game_core.h"
#include "battle_game/graphics/graphics.h"

namespace battle_game::unit {

namespace {
uint32_t peashooter_model_index = 0xffffffffu;
uint32_t tank_turret_model_index = 0xffffffffu; // 声明 tank_turret_model_index
}  // namespace


Peashooter::Peashooter(GameCore *game_core, uint32_t id, uint32_t player_id)
    : Unit(game_core, id, player_id) {
  if (!~peashooter_model_index) {
    auto mgr = AssetsManager::GetInstance();
      /*body*/
      peashooter_model_index = mgr->RegisterModel(
        {
            {{0.0f, 0.05f}, {0.0f, 0.0f}, {0.0f, 0.5f, 0.0f, 1.0f}},
            {{0.0f, -0.05f}, {0.0f, 0.0f}, {0.0f, 0.5f, 0.0f, 1.0f}},
            {{1.0f, 0.05f}, {0.0f, 0.0f}, {0.0f, 0.5f, 0.0f, 1.0f}},
            {{1.0f, -0.05f}, {0.0f, 0.0f}, {0.0f, 0.5f, 0.0f, 1.0f}},

            {{0.15f, 0.05f}, {0.0f, 0.0f}, {0.0f, 0.3f, 0.0f, 1.0f}},
            {{0.5f, 0.3f}, {0.0f, 0.0f}, {0.0f, 0.3f, 0.0f, 1.0f}},
            {{0.75f, 0.45f}, {0.0f, 0.0f}, {0.0f, 0.3f, 0.0f, 1.0f}},
            {{0.4f, 0.6f}, {0.0f, 0.0f}, {0.0f, 0.3f, 0.0f, 1.0f}},

            {{0.15f, -0.05f}, {0.0f, 0.0f}, {0.0f, 0.3f, 0.0f, 1.0f}},
            {{0.5f, -0.3f}, {0.0f, 0.0f}, {0.0f, 0.3f, 0.0f, 1.0f}},
            {{0.75f, -0.45f}, {0.0f, 0.0f}, {0.0f, 0.3f, 0.0f, 1.0f}},
            {{0.4f, -0.6f}, {0.0f, 0.0f}, {0.0f, 0.3f, 0.0f, 1.0f}},

            {{1.3f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},//12

            {{1.8f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},//13
            {{1.78f, 0.13f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.73f, 0.25f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.65f, 0.35f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.55f, 0.43f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.43f, 0.48f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.3f, 0.5f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},//19
            {{1.17f, 0.48f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.05f, 0.43f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{0.95f, 0.35f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{0.87f, 0.25f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{0.82f, 0.13f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{0.8f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},//25
            {{0.82f, -0.13f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{0.87f, -0.25f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{0.95f, -0.35f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.05f, -0.43f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.17f, -0.48f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.3f, -0.5f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},//31
            {{1.43f, -0.48f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.55f, -0.43f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.65f, -0.35f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.73f, -0.25f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.78f, -0.13f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.8f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},//37

            {{1.1f, 0.9f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.5f, 0.9f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.1f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},
            {{1.5f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.9f, 0.0f, 1.0f}},


        },
        {0, 1, 2, 
        1, 2, 3, 
        4, 5, 6,
        4, 6, 7,
        8, 9, 10, 
        8, 10, 11,
        12,13,14,
        12,14,15,
        12,15,16,
        12,16,17,
        12,17,18,
        12,18,19,
        12,19,20,
        12,20,21,
        12,21,22,
        12,22,23,
        12,23,24,
        12,24,25,
        12,25,26,
        12,26,27,
        12,27,28,
        12,28,29,
        12,29,30,
        12,30,31,
        12,31,32,
        12,32,33,
        12,33,34,
        12,34,35,
        12,35,36,
        12,36,37,
        12,37,13,
        38,39,40,
        39,40,41});
  }  
  
}

void Peashooter::Render() {
  battle_game::SetTransformation(position_, rotation_);
  battle_game::SetTexture(0);
  battle_game::SetColor({0.0f, 1.0f, 0.0f, 1.0f});
  battle_game::DrawModel(peashooter_model_index);
}

void Peashooter::Update() {
  PeaMove(3.0f, glm::radians(180.0f)); // 调用 PeaMove
  TurretRotate(); // 调用 TurretRotate 更新炮塔方向
  Fire();
}

void Peashooter::PeaMove(float move_speed, float rotate_angular_speed) {
  auto player = game_core_->GetPlayer(player_id_);
  if (player) {
    auto &input_data = player->GetInputData();
    glm::vec2 offset{0.0f};
    if (input_data.key_down[GLFW_KEY_W]) {
      offset.y += 1.0f;
    }
    if (input_data.key_down[GLFW_KEY_S]) {
      offset.y -= 1.0f;
    }
    float speed = move_speed * GetSpeedScale();
    offset *= kSecondPerTick * speed;
    auto new_position =
        position_ + glm::vec2{glm::rotate(glm::mat4{1.0f}, rotation_,
                                          glm::vec3{0.0f, 0.0f, 1.0f}) *
                              glm::vec4{offset, 0.0f, 0.0f}};
    if (!game_core_->IsBlockedByObstacles(new_position)) {
      game_core_->PushEventMoveUnit(id_, new_position);
    }
    float rotation_offset = 0.0f;
    if (input_data.key_down[GLFW_KEY_A]) {
      rotation_offset += 1.0f;
    }
    if (input_data.key_down[GLFW_KEY_D]) {
      rotation_offset -= 1.0f;
    }
    rotation_offset *= kSecondPerTick * rotate_angular_speed * GetSpeedScale();
    game_core_->PushEventRotateUnit(id_, rotation_ + rotation_offset);
  }
}

void Peashooter::TurretRotate() {
  auto player = game_core_->GetPlayer(player_id_);
  if (player) {
    auto &input_data = player->GetInputData();
    auto diff = input_data.mouse_cursor_position - position_;
    if (glm::length(diff) < 1e-4) {
      turret_rotation_ = rotation_;
    } else {
      turret_rotation_ = std::atan2(diff.y, diff.x) - glm::radians(90.0f);
    }
  }
}

void Peashooter::Fire() {
  if (fire_count_down_ == 0) {
    auto velocity = Rotate(glm::vec2{0.0f, 10.0f}, turret_rotation_);
    GenerateBullet<bullet::PeaBullet>(
        position_ + Rotate({0.0f, 1.0f}, turret_rotation_), turret_rotation_, GetDamageScale(), velocity);
    fire_count_down_ = kTickPerSecond;
  }
  if (fire_count_down_) {
    fire_count_down_--;
  }
}

bool Peashooter::IsHit(glm::vec2 position) const {
  position = WorldToLocal(position);
  return position.x > -0.5f && position.x < 0.5f && position.y > -0.5f && position.y < 0.5f;
}

const char *Peashooter::UnitName() const {
  return "Peashooter";
}

const char *Peashooter::Author() const {
  return "Sun Rongxi";
}

}  // namespace battle_game::unit