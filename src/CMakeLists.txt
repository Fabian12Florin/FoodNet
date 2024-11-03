add_library(core_sources
    Prajitura.cpp
    Blat.cpp
    Crema.cpp
    Fructe.cpp
    Ingredient.cpp
    ComponentaCuIngrediente.cpp
)

add_executable(FoodNet main.cpp)
target_link_libraries(FoodNet core_sources)