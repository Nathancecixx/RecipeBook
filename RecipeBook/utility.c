#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utility.h"


bool AddNewRecipeToList(PLISTNODE* ListHead) {

    //    Take the recipes name
    printf(""
        "\n+--------------------------------------------------------+"
        "\n|                  Adding a new recipe:                  |"
        "\n+--------------------------------------------------------+");

    RECIPE_TYPE RecipeType = takeInputAsRecipeType("What kind of recipe is this?");
    char* recipeName = takeInputAsString("\nPlease enter the recipe's name");

    if (SearchNodeInList(ListHead, recipeName)) {
        printf("Recipe already added.\n");
        return false;
    }



    //    Create an Ingredient list for the recipe.
    int numOfIngredients = CHUNK_OF_LIST;
    INGREDIENT* IngredientList = (INGREDIENT*)malloc(sizeof(INGREDIENT) * numOfIngredients);
    if (IngredientList == NULL) {
        free(recipeName);
        return false;
    }


    INGREDIENT* tmpPtr = NULL;
    int count = 0;

    //    Populate list, dynamically resizing based on how many inputs
    do {
        //        Checks if there's enough space allocated in the ingredient list.
        if (count >= numOfIngredients) {
            numOfIngredients += CHUNK_OF_LIST;
            tmpPtr = IngredientList;
            IngredientList = realloc(IngredientList, (sizeof(INGREDIENT) * numOfIngredients));
            if (IngredientList == NULL) {
                free(tmpPtr);
                free(recipeName);
                return false;
            }
        }

        //        There is enough space so add a new Ingredient
        char* ingredientName = takeInputAsString("Please enter Ingredient's name");
        IngredientList[count] = CreateIngredient(count, ingredientName);
        free(ingredientName);
        count++;

    } while (takeInputAsChar("Would you like to add another Ingredient? (Y/N)") == 'y');



    //    Create a Steps list for the recipe.
    int numOfSteps = CHUNK_OF_LIST;
    STEP* StepsList = (STEP*)malloc(sizeof(STEP) * numOfSteps);
    if (StepsList == NULL) {
        free(recipeName);
        free(IngredientList);
        return false;
    }
    /********************************
     * IMPLEMENT STEPS BUILDER HERE *
     ********************************/

     //    Create the recipe and free tmp name memory
    RECIPE recipe = CreateRecipe(recipeName, RecipeType, count, IngredientList, StepsList);
    free(recipeName);


    //    Add node to list
    return AddNodeToList(ListHead, recipe);
}

bool DeleteRecipeFromList(PLISTNODE* ListHead) {
    //    Take the recipes name
    printf(""
        "\n+--------------------------------------------------------+"
        "\n|                    Deleting recipe:                    |"
        "\n+--------------------------------------------------------+");
    char* recipeName = takeInputAsString("\nPlease enter the recipe's name");

    if (!RemoveNodeFromList(ListHead, recipeName)) {
        free(recipeName);
        return false;
    }

    free(recipeName);
    return true;
}

/*bool UpdateRecipeInList(PLISTNODE* ListHead){

}*/

bool DisplayOptions(PLISTNODE* ListHead) {

    printf(""
        "\n+--------------------------------------------------------+"
        "\n|                     Display Menu:                      |"
        "\n+--------------------------------------------------------+");
    printf(""
        "\n+--------------------------------------------------------+\n"
        "| Choose how you would like to display:                  |\n"
        "| a) Display Single Recipe                               |\n"
        "| b) Display Range Of Recipes                            |\n"
        "| c) Display All Recipes                                 |\n"
        "| d) Back                                                |\n"
        "+--------------------------------------------------------+\n");
    int flag = 1;

    while (flag) {
        char input = takeInputAsChar("To choose an option, enter its letter label: ");
        switch (input) {
        case 'a':
            return DisplaySingleRecipe(ListHead);
        case 'b':
            return DisplayRecipeRange(ListHead);
        case 'c':
            return DisplayAllRecipe(ListHead);
        case 'd':
            flag = 0;
            break;
        default:
            fprintf(stderr, "INPUT ERROR: Please try again\n");
            break;
        }
    }

    return true;

}

bool DisplaySingleRecipe(PLISTNODE* ListHead) {
    return false;
}

bool DisplayRecipeRange(PLISTNODE* ListHead) {
    RECIPE_TYPE recipeType = takeInputAsRecipeType("What would you like to sort by?");
    DisplayListRange(*ListHead, recipeType);

    return true;
}

bool DisplayAllRecipe(PLISTNODE* ListHead) {
    printf(""
        "\n+--------------------------------------------------------+"
        "\n|                       Recipes:                         |"
        "\n+--------------------------------------------------------+");
    DisplayList(*ListHead);
    return true;
}

/*bool SearchForRecipeInList(PLISTNODE* ListHead){

}*/

RECIPE_TYPE takeInputAsRecipeType(char* Prompt) {
    printf(""
        "\n+--------------------------------------------------------+\n"
        "| a) Breakfast                                           |\n"
        "| b) Lunch                                               |\n"
        "| c) Dinner                                              |\n"
        "| d) Snack                                               |\n"
        "+--------------------------------------------------------+\n");
    printf("%s\n", Prompt);

    while (1) {
        char input = takeInputAsChar("");
        switch (input) {
        case 'a':
            return BREAKFAST;
        case 'b':
            return LUNCH;
        case 'c':
            return DINNER;
        case 'd':
            return SNACK;
        default:
            printf("Invalid input, please try again");
        }
    }
}

char takeInputAsChar(char* Prompt) {

    printf("%s\n", Prompt);
    char buffer[3];
    if (fgets(buffer, 3, stdin) == NULL) {
        fprintf(stderr, "INPUT ERROR: Failed to read menu input with fgets\n");
        return '\0';
    }

    if (buffer[0] >= 'A' && buffer[0] <= 'Z') {
        buffer[0] += DIFF_BETWEEN_CASES;
    }

    if (strcspn(buffer, "\n") == strlen(buffer)) {
        clearInputBuffer();
    }

    return buffer[0];
}

char* takeInputAsString(char* Prompt) {
    printf("%s\n", Prompt);

    bool flag = true;
    char buffer[MAX_RECIPE_NAME];

    while (flag) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "INPUT ERROR: Failed to read menu input with fgets\n");
            return NULL;
        }

        //    Check input
        if (strcspn(buffer, "\n") == strlen(buffer)) {
            clearInputBuffer();
            printf("Name is too long, please try again.\n");
        }
        else {
            flag = false;
        }
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    char* name = (char*)malloc(strlen(buffer) + 1);

    if (name == NULL) {
        fprintf(stderr, "MALLOC ERROR: Failed to allocate memory.");
        return NULL;
    }

    strncpy(name, buffer, strlen(buffer) + 1);
    return name;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}