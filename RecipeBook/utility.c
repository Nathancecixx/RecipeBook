#include "utility.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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


    INGREDIENT* tmpIngredientPtr = NULL;
    int ingredientCount = 0;

    //    Populate list, dynamically resizing based on how many inputs
    do {
        //        Checks if there's enough space allocated in the ingredient list.
        if (ingredientCount >= numOfIngredients) {
            numOfIngredients += CHUNK_OF_LIST;
            tmpIngredientPtr = IngredientList;
            IngredientList = realloc(IngredientList, (sizeof(INGREDIENT) * numOfIngredients));
            if (IngredientList == NULL) {
                free(tmpIngredientPtr);
                free(recipeName);
                return false;
            }
        }

        //        There is enough space so add a new Ingredient
        char* ingredientName = takeInputAsString("Please enter Ingredient's name");
        IngredientList[ingredientCount] = CreateIngredient(ingredientCount, ingredientName);
        free(ingredientName);
        ingredientCount++;

    } while (takeInputAsChar("Would you like to add another Ingredient? (Y/N)") == 'y');



    //    Create a Steps list for the recipe.
    int numOfSteps = CHUNK_OF_LIST;
    STEP* StepsList = (STEP*)malloc(sizeof(STEP) * numOfSteps);
    if (StepsList == NULL) {
        free(recipeName);
        free(IngredientList);
        return false;
    }

    STEP* tmpStepPtr = NULL;
    int stepCount = 0;

    //    Populate list, dynamically resizing based on how many inputs
    do {
        //        Checks if there's enough space allocated in the steps list.
        if (stepCount >= numOfSteps) {
            numOfSteps += CHUNK_OF_LIST;
            tmpStepPtr = StepsList;
            StepsList = realloc(StepsList, (sizeof(STEP) * numOfSteps));
            if (StepsList == NULL) {
                free(tmpStepPtr);
                free(recipeName);
                return false;
            }
        }

        //        There is enough space so add a new Ingredient
        char* StepSentance = takeInputAsSentance("Please enter the Step");
        StepsList[stepCount] = CreateStep(stepCount, StepSentance);
        stepCount++;

    } while (takeInputAsChar("Would you like to add another Step? (Y/N)") == 'y');


    //    Create the recipe and free tmp name memory
    RECIPE recipe = CreateRecipe(recipeName, RecipeType, ingredientCount, IngredientList, stepCount, StepsList);
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

bool UpdateRecipeInList(PLISTNODE* ListHead) {
    printf(""
        "\n+--------------------------------------------------------+"
        "\n|                   Edit Recipe Menu:                    |"
        "\n+--------------------------------------------------------+\n");

    char* userInput = takeInputAsString("Enter the name of the recipe you would like to edit(Type 'Back' to exit)");

    //    Prompt until valid recipe is entered
    while (SearchNodeInList(ListHead, userInput) != true) {
        if (strcmp("Back", userInput) == 0)
            return false;

        userInput = takeInputAsString("Recipe not found, please try again");
    }


    printf(""
        "\n+--------------------------------------------------------+\n"
        "| Choose how you would like to edit:                     |\n"
        "| a) Recipe Name                                         |\n"
        "| b) Recipe Type                                         |\n"
        "| c) Ingredient List                                     |\n"
        "| d) Steps List                                          |\n"
        "| e) Back                                                |\n"
        "+--------------------------------------------------------+\n");

    int flag = 1;

    while (flag) {
        char input = takeInputAsChar("To choose an option, enter its letter label: ");
        switch (input) {
        case 'a':
            //TODO: Edit recipe name
        case 'b':
            //TODO: Edit Recipe Type
        case 'c':
            editIngredient(getRecipe(ListHead, userInput));
            flag = 0;
            break;
        case 'd':
            //TODO: Edit Steps List
            break;
        case 'e':
            flag = 0;
            break;
        default:
            fprintf(stderr, "INPUT ERROR: Please try again\n");
            break;
        }
    }

    return true;
}

RECIPE* getRecipe(PLISTNODE* ListHead, char* Name)
{
    PLISTNODE current = *ListHead;

    //    There is a first item and its not what we want.
    //    iterate through list until we find it or end
    PLISTNODE prev = NULL;
    while (current != NULL && strcmp(current->recipe.name, Name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return NULL;
    }

    return &current->recipe;
}


bool editIngredient(RECIPE* recipe)
{
    int flag = 1;

    int userInput = 0;
    printf("Press 1 to add a new ingredient, and press 2 to edit an existing ingredient\n");

    while (scanf("%d", &userInput) != 1 || (userInput != 1 && userInput != 2))
    {
        printf("Invalid input, Please enter 1 or 2");
        clearInputBuffer();
    }

    if (userInput == 1)
    {
        int ingredientNum = recipe->ingredientCount;
        INGREDIENT* ingredientList = recipe->ingredientList;
        INGREDIENT* tempIngredientPtr = ingredientList;

        ingredientList = realloc(ingredientList, (sizeof(INGREDIENT) * ingredientNum));
        if (ingredientList == NULL)
        {
            printf("Failed to create a new ingredient");
            ingredientList = tempIngredientPtr;
            return false;
        }

        
        char* name = (char*)malloc((MAX_RECIPE_NAME) + 1);

        strncpy(name, takeUpdatedIngredientName("Please input the new Ingredient: "), MAX_RECIPE_NAME);

        ingredientList[ingredientNum] = CreateIngredient(ingredientNum + 1, name);

        free(name);
        recipe->ingredientCount++;
    }
    else if (userInput == 2)
    {
        int ingredientChoice = 0;
        printf("Please select the ingredient you'd like to edit by entering its corresponding number\n");
        for (int i = 0; i < recipe->ingredientCount; i++)
        {
            int displayNumber = i+1;
            printf("%d) %s\n",displayNumber, getIngredient(recipe->ingredientList[i]));
        }
        while (scanf("%d", &ingredientChoice) != 1 || (ingredientChoice < 0 || ingredientChoice > recipe->ingredientCount))
        {
            printf("Invalid input, please enter one of the corresponding numbers");
            clearInputBuffer();
        }

        ingredientChoice--;

        char* updatedIngredient = takeUpdatedIngredientName("Please enter the updated ingredient: ");
        strncpy(recipe->ingredientList[ingredientChoice].name, updatedIngredient, MAX_RECIPE_NAME);
        return true;
    }
}

char* takeUpdatedIngredientName(char* prompt)
{
    printf("\n%s", prompt);

    char userInput[MAX_RECIPE_NAME];

    clearInputBuffer();

    while (fgets(userInput, sizeof(userInput), stdin) == NULL)
    {
        printf("Issue taking updated ingredient name, please try again");
    }

    return userInput;
}

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
    char* recipeName = takeInputAsString("Please enter the name of the name of the recipe you wish to display: ");

    if (!SearchNodeInList(ListHead, recipeName))
    {
        printf("This recipe does not exist");
        return false;
    }
    RECIPE* recipeToPrint = getRecipe(ListHead, recipeName);

    DisplayRecipe(*recipeToPrint);
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

bool SearchForRecipeInList(PLISTNODE* ListHead) {

    //    Take the recipes name
    printf(""
        "\n+--------------------------------------------------------+"
        "\n|                  Search for a recipe:                  |"
        "\n+--------------------------------------------------------+");

    char* recipeName = takeInputAsString("\nPlease enter the recipe's name you wish to search for:");

    if (SearchNodeInList(ListHead, recipeName)) {
        printf("\nRecipe exists!\n");

    }
    else {
        printf("\nRecipe has not been added yet.\n");
    }
    return true;
}

char* takeInputAsSentance(char* Prompt) {

    printf("%s\n", Prompt);

    //    Size is set to 1 chunk of chars which is 20,
    //    this allocationInChars increments in chunks whenever the
    //    input is greater than the current allocationInChars
    int allocationInChars = CHUNK_OF_LIST;

    char* userString = (char*)malloc(sizeof(char) * allocationInChars);
    if (userString == NULL)
        return NULL;

    //    temp pointer to avoid memory leaks when re allocating memory
    char* tmpPtr = NULL;
    int charCount = 0;
    char currentChar;

    //    loops until end of line or file
    while ((currentChar = (char)getc(stdin)) != '\n' && currentChar != EOF) {

        userString[charCount] = currentChar;

        charCount++;

        //        Checks if there are more chars than the allocationInChars of allocation,
        //        if so then add another chunk and re-allocate
        if (charCount >= allocationInChars) {
            allocationInChars += CHUNK_OF_LIST;
            tmpPtr = userString;
            userString = realloc(userString, (sizeof(char) * allocationInChars));
            if (userString == NULL) {
                free(tmpPtr);
                return NULL;
            }
        }
    }

    //    Sets null terminator and returns string
    userString[charCount] = '\0';
    return userString;
}

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