#include <iostream>
#include <list>
#include <string>
#include "gtest/gtest.h"



// #include "controller.h"
// #include "board.h"
// #include "view.h"
// #include "cell.h"
// #include "manager.h"
// #include "mockBoard.h"

// Board* board = new Board();
// Manager* manager = new Manager(true);
// MockBoard* tboard = new MockBoard();
// char** tmatrix = tboard->MakeTestBoard(4);

// // board
// TEST(IsExistTest, F) { EXPECT_EQ(board->IsExist(), false); }
// TEST(SetBoardTest, invalidVal) { EXPECT_EQ(board->SetBoard(0), false); }
// TEST(SetBoardTest, validVal) { EXPECT_EQ(board->SetBoard(4), true); }
// TEST(GetBoardTest, board) {
//   char** matrix = board->GetBoard();
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       EXPECT_EQ(matrix[i][j], tmatrix[i][j]);
//     }
//   }
// }
// TEST(GetBoardSizeTest, size) { EXPECT_EQ(board->GetBoardSize(), 4); }

// TEST(IsExistTest, T) {
//   board->SetBoard(3);
//   EXPECT_EQ(board->IsExist(), true);
// }

// // manage
// TEST(NoPlaceTest, Empty) { EXPECT_EQ(manager->NoPlace(), 3); }

// TEST(CheckOrderTEST, order) {
//   Board* temp = new Board();
//   temp->SetBoard(3);
//   temp->SetMatrix(1, 2, 'o');
//   temp->SetMatrix(1, 3, 'x');
//   board->SetBoard(3);

//   char** matrix = board->GetBoard();
//   char** tmatrix = temp->GetBoard();

//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 3; j++) {
//       EXPECT_EQ(matrix[i][j], tmatrix[i][j]);
//     }
//   }
// }

// TEST(CheckPointTEST, Empty) {
//   board->SetBoard(3);
//   EXPECT_EQ(manager->CheckPoint(true, tmatrix, 4), true);
// }

// TEST(CheckTest, OrderOk) {
//   board->SetBoard(3);
//   EXPECT_EQ(manager->Check(board, true), 0);
// }

// TEST(CheckOutsideTest, Outside) {
//   board->SetBoard(3);
//   EXPECT_EQ(manager->CheckOutside(board, 7, 10), 1);
// }

// TEST(CheckEmptyTest, Empty) {
//   board->SetBoard(3);
//   board->SetMatrix(0, 1, '.');
//   EXPECT_EQ(manager->CheckEmpty(board, 0, 1), 0);
// }

// // view
// View* view = new View();
// TEST(PrintSetBoardErrorTest, str) {
//   testing::internal::CaptureStdout();
//   view->PrintSetBoardError();
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "보드 사이즈를 다시 입력하세요.\n");
// }

// TEST(PrintOrderErrorTest, 1) {
//   testing::internal::CaptureStdout();
//   view->PrintOrderError(1);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "둘 수 없는 곳입니다. (잘못된 좌표)\n");
// }

// TEST(PrintOrderErrorTest, 2) {
//   testing::internal::CaptureStdout();
//   view->PrintOrderError(2);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "둘 수 없는 곳입니다. (이미 돌이 놓인 곳)\n");
// }

// TEST(PrintOrderErrorTest, 3) {
//   testing::internal::CaptureStdout();
//   view->PrintOrderError(3);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "둘 수 없는 곳입니다. (바꿀 수 있는 돌이 없음)\n");
// }

// TEST(PrintSetBoardErrorTest, SetBoardError) {
//   testing::internal::CaptureStdout();
//   view->PrintSetBoardError();
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "보드 사이즈를 다시 입력하세요.\n");
// }

// TEST(PrintCheckErrorTest, 1) {
//   testing::internal::CaptureStdout();
//   view->PrintCheck(1);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "빈 공간이 없습니다.\n\n");
// }

// TEST(PrintCheckErrorTest, 2) {
//   testing::internal::CaptureStdout();
//   view->PrintCheck(2);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "모든 돌이 검정색입니다.\n\n");
// }

// TEST(PrintCheckErrorTest, 3) {
//   testing::internal::CaptureStdout();
//   view->PrintCheck(3);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "모든 돌이 흰색입니다.\n\n");
// }

// TEST(PrintCheckErrorTest, 4) {
//   testing::internal::CaptureStdout();
//   view->PrintCheck(4);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked, "흑 백 모두 둘 수 있는 곳이 없습니다.\n\n");
// }

// TEST(PrintCheckErrorTest, 5) {
//   testing::internal::CaptureStdout();
//   view->PrintCheck(5);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked,
//             "흑이 둘 수 있는 곳이 없으므로 차례를 백에게 넘깁니다.\n\n");
// }

// TEST(PrintCheckErrorTest, 6) {
//   testing::internal::CaptureStdout();
//   view->PrintCheck(6);
//   std::string invoked = testing::internal::GetCapturedStdout();
//   EXPECT_EQ(invoked,
//             "백이 둘 수 있는 곳이 없으므로 차례를 흑에게 넘깁니다.\n\n");
// }
