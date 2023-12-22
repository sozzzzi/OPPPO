#include "../lib/maincycle.h"
#include "gtest/gtest.h"

TEST(BasicTests, BadFile)
{
    MainCycle mp;
    std::string test_not_exist_file = "asdsdsadlkswajkldasjkdjaslk.txt";

    ASSERT_EQ(NonExistFile, mp.run(test_not_exist_file));
}

TEST(BasicTests, PrintEmptyList)
{
    MainCycle mp;
    ASSERT_EQ(EmptyList, mp.figures->printList());
}

TEST(InsertTests, AddNoParams)
{
    MainCycle mp;
    std::string empty_param_string = "";
    ASSERT_EQ(NonExistObject, mp.addCommand(empty_param_string));
}

TEST(InsertTests, AddCircleNoParams)
{
    MainCycle mp;
    std::string test_only_circle = "circle";
    ASSERT_EQ(NotEnoughData, mp.addCommand(test_only_circle));
}

TEST(InsertTests, AddCircleOneParam)
{
    MainCycle mp;
    std::string test_circle_one_var = "circle 1";

    ASSERT_EQ(NotEnoughData, mp.addCommand(test_circle_one_var));
}

TEST(InsertTests, AddCircleNoColor)
{
    MainCycle mp;
    std::string test_without_color = "circle 1 2 3";
    ASSERT_EQ(NotEnoughData, mp.addCommand(test_without_color));
}

TEST(InsertTests, AddCircleBadParam)
{
    MainCycle mp;
    std::string test_bad_input = "circle 1 ewewewe 3 red";
    ASSERT_EQ(BadInput, mp.addCommand(test_bad_input));
}

TEST(InsertTests, AddCircleBadColor)
{
    MainCycle mp;
    std::string test_bad_color_circle = "circle 1 2 3 gray";
    ASSERT_EQ(NonExistColor, mp.addCommand(test_bad_color_circle));
}

TEST(InsertTests, AddCircleCorrect)
{
    MainCycle mp;
    std::string test_correct_circle = "circle 1 2 3 red";
    ASSERT_EQ(Ok, mp.addCommand(test_correct_circle));
}

TEST(InsertTests, AddRectNoParams)
{
    MainCycle mp;
    std::string test_only_rectangle = "rectangle";
    ASSERT_EQ(NotEnoughData, mp.addCommand(test_only_rectangle));
}

TEST(InsertTests, AddRectOneParam)
{
    MainCycle mp;
    std::string test_rectangle_one_var = "rectangle 1.5";
    ASSERT_EQ(NotEnoughData, mp.addCommand(test_rectangle_one_var));
}

TEST(InsertTests, AddRectNoColor)
{
    MainCycle mp;
    std::string test_rectangle_without_color = "rectangle 999.9 500 456.7 888.8";
    ASSERT_EQ(NotEnoughData, mp.addCommand(test_rectangle_without_color));
}

TEST(InsertTests, AddRectBadColor)
{
    MainCycle mp;
    std::string test_bad_color_rectangle = "rectangle 123.9 777 123.9 777 gray";
    ASSERT_EQ(NonExistColor, mp.addCommand(test_bad_color_rectangle));
}

TEST(InsertTests, AddRectCorrect)
{
    MainCycle mp;
    std::string test_correct_rectangle = "rectangle 123.9 777 123.9 777 red";
    ASSERT_EQ(Ok, mp.addCommand(test_correct_rectangle));
}

TEST(InsertTests, AddTriNoParams)
{
    MainCycle mp;
    std::string test_only_triangle = "triangle";
    ASSERT_EQ(NotEnoughData, mp.addCommand(test_only_triangle));
}

TEST(InsertTests, AddTriOneParam)
{
    MainCycle mp;
    std::string test_triangle_one_var = "triangle 1";
    ASSERT_EQ(NotEnoughData, mp.addCommand(test_triangle_one_var));
}

TEST(InsertTests, AddTriNoColor)
{
    MainCycle mp;
    std::string test_triangle_without_color = "triangle 1 2 3 1 2 3";
    ASSERT_EQ(NotEnoughData, mp.addCommand(test_triangle_without_color));
}

TEST(InsertTests, AddTriBadColor)
{
    MainCycle mp;
    std::string test_bad_color_triangle = "triangle 1 2 3 1 2 3 gray";

    ASSERT_EQ(NonExistColor, mp.addCommand(test_bad_color_triangle));
}

TEST(InsertTests, AddTriCorrect)
{
    MainCycle mp;
    std::string test_correct_triangle = "triangle 1 2 3 1 2 3 red";
    ASSERT_EQ(Ok, mp.addCommand(test_correct_triangle));
}

TEST(DeleteTests, DeleteAll)
{
    MainCycle mp;
    std::string test_correct_triangle = "triangle 1 2 3 4 5 6 red";
    std::string test_params = "*";
    mp.addCommand(test_correct_triangle);
    mp.addCommand(test_correct_triangle);
    mp.addCommand(test_correct_triangle);
    mp.remCommand(test_params);

    ASSERT_EQ(0, mp.figures->getSize());
}

TEST(DeleteTests, DeleteExistColor)
{
    MainCycle mp;
    std::string test_correct_circle = "circle 1 2 3 red";
    mp.addCommand(test_correct_circle);
    test_correct_circle = "circle 1 2 3 blue";
    mp.addCommand(test_correct_circle);
    mp.addCommand(test_correct_circle);
    std::string test_color = "color red";
    mp.remCommand(test_color);

    ASSERT_EQ(2, mp.figures->getSize());
}

TEST(DeleteTests, DeleteNonExistColor)
{
    MainCycle mp;
    std::string test_correct_triangle = "triangle 1 2 3 4 5 6 red";

    mp.addCommand(test_correct_triangle);
    mp.addCommand(test_correct_triangle);
    mp.addCommand(test_correct_triangle);
    std::string test_color = "color blue";
    mp.remCommand(test_color);

    ASSERT_EQ(3, mp.figures->getSize());
}

TEST(DeleteTests, DeleteAllExistColor)
{
    MainCycle mp;
    std::string test_correct_triangle = "triangle 1 2 3 4 5 6 red";

    mp.addCommand(test_correct_triangle);
    mp.addCommand(test_correct_triangle);
    mp.addCommand(test_correct_triangle);
    std::string test_color = "color red";
    mp.remCommand(test_color);

    ASSERT_EQ(0, mp.figures->getSize());
}

TEST(DeleteTests, DeleteAllExistCircle)
{
    MainCycle mp;
    std::string test_correct_circle = "circle 1 2 3 red";

    mp.addCommand(test_correct_circle);
    mp.addCommand(test_correct_circle);
    mp.addCommand(test_correct_circle);
    std::string test_params = "circle";
    mp.remCommand(test_params);
    ASSERT_EQ(0, mp.figures->getSize());
}

TEST(DeleteTests, DeleteAllExistRect)
{
    MainCycle mp;
    std::string test_correct_rectangle = "rectangle 1 2 3 4 red";

    mp.addCommand(test_correct_rectangle);
    mp.addCommand(test_correct_rectangle);
    mp.addCommand(test_correct_rectangle);
    std::string test_params = "rectangle";
    mp.remCommand(test_params);
    ASSERT_EQ(0, mp.figures->getSize());
}

TEST(DeleteTests, DeleteAllExistTri)
{
    MainCycle mp;
    std::string test_correct_triangle = "triangle 1 2 3 4 5 6 red";

    mp.addCommand(test_correct_triangle);
    mp.addCommand(test_correct_triangle);
    mp.addCommand(test_correct_triangle);
    std::string test_params = "triangle";
    mp.remCommand(test_params);
    ASSERT_EQ(0, mp.figures->getSize());
}

TEST(DeleteTests, DeleteNonExistCircle)
{
    MainCycle mp;
    std::string test_correct_circle_1 = "circle 1 2 3 red";
    std::string test_correct_circle_2 = "circle 5 6 2";
    mp.addCommand(test_correct_circle_1);

    ASSERT_EQ(1, mp.figures->getSize());
}

TEST(DeleteTests, DeleteExistCircle)
{
    MainCycle mp;
    std::string test_correct_circle_1 = "circle 1 2 3 red";
    std::string test_correct_circle_2 = "circle 1 2 3";

    mp.addCommand(test_correct_circle_1);
    mp.remCommand(test_correct_circle_2);

    ASSERT_EQ(0, mp.figures->getSize());
}

TEST(DeleteTests, DeleteNonExistRect)
{
    MainCycle mp;
    std::string test_correct_rectangle_1 = "rectangle 1 2 3 4 red";
    std::string test_correct_rectangle_2 = "rectangle 5 6 2 1";
    mp.addCommand(test_correct_rectangle_1);
    mp.remCommand(test_correct_rectangle_2);

    ASSERT_EQ(1, mp.figures->getSize());
}

TEST(DeleteTests, DeleteExistRect)
{
    MainCycle mp;
    std::string test_correct_rectangle_1 = "rectangle 1 2 3 4 red";
    std::string test_correct_rectangle_2 = "rectangle 1 2 3 4";
    mp.addCommand(test_correct_rectangle_1);
    mp.remCommand(test_correct_rectangle_2);

    ASSERT_EQ(0, mp.figures->getSize());
}

TEST(DeleteTests, DeleteNonExistTri)
{
    MainCycle mp;
    std::string test_correct_triangle_1 = "triangle 1 2 3 4 5 6 red";
    std::string test_correct_triangle_2 = "triangle 5 6 2 1 1 1";
    mp.addCommand(test_correct_triangle_1);
    mp.remCommand(test_correct_triangle_2);

    ASSERT_EQ(1, mp.figures->getSize());
}

TEST(DeleteTests, DeleteExistTri)
{
    MainCycle mp;
    std::string test_correct_triangle_1 = "triangle 1 2 3 4 5 6 red";
    std::string test_correct_triangle_2 = "triangle 1 2 3 4 5 6";
    mp.addCommand(test_correct_triangle_1);
    mp.remCommand(test_correct_triangle_2);

    ASSERT_EQ(0, mp.figures->getSize());
}

TEST(ContainerTests, AddFirstElemList)
{

    std::unique_ptr<FlatFigure> new_obj = std::make_unique<Circle>("1", "2", "3", "red");
    std::unique_ptr<List> objs = std::make_unique<List>();

    try
    {
        objs->addList(new_obj.get());
    }
    catch (const char* error_message)
    {
        std::cerr << '\n' << error_message << '\n';
        return;
    }
    ASSERT_EQ(1, objs->getSize());
}

TEST(ContainerTests, AddNextElemList)
{
    std::unique_ptr<FlatFigure> new_obj = std::make_unique<Circle>("1", "2", "3", "red");
    std::unique_ptr<List> objs = std::make_unique<List>();

    objs->addList(new_obj.get());

    try
    {
        objs->addList(new_obj.get());
    }
    catch (const char* error_message)
    {
        std::cerr << '\n' << error_message << '\n';
        return;
    }

    ASSERT_EQ(2, objs->getSize());
}

TEST(ContainerTests, AddNextElemListAfterDel)
{
    std::unique_ptr<FlatFigure> new_obj = std::make_unique<Circle>("1", "2", "3", "red");
    std::unique_ptr<List> objs = std::make_unique<List>();

    objs->addList(new_obj.get());
    objs->addList(new_obj.get());
    objs->deleteElem(1);

    try
    {
        objs->addList(new_obj.get());
    }
    catch (const char* error_message)
    {
        FAIL() << error_message;
    }
    ASSERT_EQ(2, objs->getSize());
}

TEST(ContainerTests, DeleteFirstElemList)
{
    std::unique_ptr<FlatFigure> new_obj = std::make_unique<Circle>("1", "2", "3", "red");
    std::unique_ptr<List> objs = std::make_unique<List>();

    objs->addList(new_obj.get());
    objs->addList(new_obj.get());
    objs->addList(new_obj.get());
    const auto expected = 2;

    try
    {
        objs->deleteElem(0);
    }
    catch (const char* error_message)
    {
        FAIL() << error_message;
    }

    if (objs->getNode(0)->next != objs->getNode(1))
    {
        FAIL() << "ERROR! Pointer to next is not true";
    }

    ASSERT_EQ(2, objs->getSize());
}

TEST(ContainerTests, DeleteMediumElemList)
{
    std::unique_ptr<FlatFigure> new_obj = std::make_unique<Circle>("1", "2", "3", "red");
    std::unique_ptr<List> objs = std::make_unique<List>();
    objs->addList(new_obj.get());
    objs->addList(new_obj.get());
    objs->addList(new_obj.get());

    try
    {
        objs->deleteElem(1);
    }
    catch (const char* error_message)
    {
        FAIL() << error_message;
    }

    if (objs->getNode(1)->next != objs->getNode(0))
    {
        FAIL() << "ERROR!";
    }
    ASSERT_EQ(2, objs->getSize());
}

TEST(ContainerTests, DeleteLastElemList)
{

    std::unique_ptr<FlatFigure> new_obj = std::make_unique<Circle>("1", "2", "3", "red");
    std::unique_ptr<List> objs = std::make_unique<List>();
    objs->addList(new_obj.get());
    objs->addList(new_obj.get());
    objs->addList(new_obj.get());

    try
    {
        objs->deleteElem(2);
    }
    catch (const char* error_message)
    {
        FAIL() << error_message;
    }
    if (objs->getNode(1)->next != objs->getNode(0))
    {
        FAIL() << "ERROR!";
    }

    ASSERT_EQ(2, objs->getSize());
}

TEST(ContainerTests, TestDeleteNotExistElemList)
{
    std::unique_ptr<FlatFigure> new_obj = std::make_unique<Circle>("1", "2", "3", "red");
    std::unique_ptr<List> objs = std::make_unique<List>();

    objs->addList(new_obj.get());

    try
    {
        objs->deleteElem(99999);
        FAIL() << "ERROR! Delete a object with index which is more than list size";
    }
    catch (std::out_of_range const & err)
    {
        EXPECT_EQ(err.what(), std::string("Out of range"));
    }
    catch(...)
    {
        FAIL() << "ERROR! Another error";
    }

}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
