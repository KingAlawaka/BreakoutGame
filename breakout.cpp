#define TINYC2_IMPLEMENTATION
#include "tinyc2.h"

#include "pixie/pixie.hpp"
#include "Windows.h"

using namespace pixie;

HWND hwnd;

void title_screen()
{
	sprite background;
	background
		.position_x(-1050)
		.bitmap("data/background.pix")
		;

	sprite logo;
	logo
		.position(80,70)
		.bitmap("data/brickBig.jpg")
		;

	play_music("data/bitpolka.xm");

	label title;
	title
		.text("The BreakOut Game")
		.font("data/Deltoid-sans.fnt")
		.position(-160.0f, 10.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(brightest_color())
		.outline(17)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

	tween(1.0f)
		.delay(1.0f)
		.property(property_position_x(&title), 160.0f)
		.ease(ease_quad_out)
		;

	label GameInstructions;
	GameInstructions
		.text("Press SPACE to Play")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(160.0f, 125.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(darkest_color())
		.outline(17)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

	label credits;
	credits
		.text("Developed Using Pixie Engine by Mattias Gustavsson")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(-160, 185.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(brightest_color())
		.outline(darkest_color())
		.shadow(darkest_color())
		;

	pixie::tween(1.0f)
		.delay(0.5f)
		.property(property_position_x(&credits), 160.0f)
		.ease(ease_quad_out)
		;

	while (is_running())
	{
		execute_frame();
		if (key_was_pressed(KEY_ESCAPE)) end(); // exit with no error
		if (key_was_pressed(KEY_RETURN)) fullscreen(!fullscreen());
		if (key_was_pressed(KEY_TAB)) crt_mode(!crt_mode());
		if (key_was_pressed(KEY_SPACE))
		{
			//logo.position(-1000, 0);
			return;
		}
			
	}
}

void GameOver_screen()
{
	play_music("data/gameover.wav");
	sprite background;
	background
		.position_x(-1050)
		.bitmap("data/background.pix")
		;

	label title;
	title
		.text("The BreakOut Game")
		.font("data/Deltoid-sans.fnt")
		.position(-160.0f, 10.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(brightest_color())
		.outline(17)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

	tween(1.0f)
		.delay(1.0f)
		.property(property_position_x(&title), 160.0f)
		.ease(ease_quad_out)
		;

	label GameOverNote;
	GameOverNote
		.text("Game Over")
		.font("data/Deltoid-sans.fnt")
		.position(160.0f, 85.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(darkest_color())
		.outline(18)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

	label GameInstructions;
	GameInstructions
		.text("Press ESC to Exit")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(160.0f, 125.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(darkest_color())
		.outline(17)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

	label credits;
	credits
		.text("Developed Using Pixie Engine by Mattias Gustavsson")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(-160, 185.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(brightest_color())
		.outline(darkest_color())
		.shadow(darkest_color())
		;

	pixie::tween(1.0f)
		.delay(0.5f)
		.property(property_position_x(&credits), 160.0f)
		.ease(ease_quad_out)
		;

	while (is_running())
	{
		execute_frame();
		if (key_was_pressed(KEY_ESCAPE)) end(); // exit with no error
		if (key_was_pressed(KEY_RETURN)) fullscreen(!fullscreen());
		if (key_was_pressed(KEY_TAB)) crt_mode(!crt_mode());
		if (key_was_pressed(KEY_SPACE)) return;
	}
}

void Won_screen()
{
	play_music("data/victory.wav");
	sprite background;
	background
		.position_x(-1050)
		.bitmap("data/background.pix")
		;

	label title;
	title
		.text("The BreakOut Game")
		.font("data/Deltoid-sans.fnt")
		.position(-160.0f, 10.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(brightest_color())
		.outline(17)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

	tween(1.0f)
		.delay(1.0f)
		.property(property_position_x(&title), 160.0f)
		.ease(ease_quad_out)
		;

	label GameOverNote;
	GameOverNote
		.text("Good Job!!! You Won")
		.font("data/Deltoid-sans.fnt")
		.position(160.0f, 85.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(darkest_color())
		.outline(18)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

	label GameInstructions;
	GameInstructions
		.text("Press ESC to Exit")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(160.0f, 125.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(darkest_color())
		.outline(17)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

	label credits;
	credits
		.text("Developed Using Pixie Engine by Mattias Gustavsson")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(-160, 185.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(brightest_color())
		.outline(darkest_color())
		.shadow(darkest_color())
		;

	pixie::tween(1.0f)
		.delay(0.5f)
		.property(property_position_x(&credits), 160.0f)
		.ease(ease_quad_out)
		;

	while (is_running())
	{
		execute_frame();
		if (key_was_pressed(KEY_ESCAPE)) end(); // exit with no error
		if (key_was_pressed(KEY_RETURN)) fullscreen(!fullscreen());
		if (key_was_pressed(KEY_TAB)) crt_mode(!crt_mode());
		if (key_was_pressed(KEY_SPACE)) return;
	}
}


int mygame()
	{
	title( "Breakout" );
	screen_size( 320, 200 );
	fullscreen( true );
	crt_mode( true ); // turn on cathode ray tube emulation shader

	u8 zero = 0;
	mouse_pointer(&zero, &zero, 1, 1);

	load_palette( "data/palette.pal" );
	play_music( "data/bitpolka.xm" );

	title_screen();

	

	//Game variables
	array<sprite*> objects;
	bool isGameStarted = false;
	POINT p;
	RECT rc;
	int scoreValue = 0;
	int livesCount = 3;
	bool isOnlyYAxis = false;

	//paddle position handler
	float xpos = 140;
	c2AABB paddleCollision;
	paddleCollision.min = c2V(xpos, 175);
	paddleCollision.max = c2V(xpos + 20, 185);
	bool isPaddleCollide = false;
	bool isMouseControl = false;
	float tempPaddleXPos = 0.0f; //this will use to smooth transition for mouse keyboard operation

	//ball postion handler
	float ballX = 150;
	float ballY = 160;
	float ballXCollision = 150;
	float ballYCollision = 160;
	float ballXMax=305, ballXMin=0, ballYMax=180, ballYMin=0;
	float ballXSpeed = 2.02f;
	float ballYSpeed = 1.007f;
	float speedingFactor = 1.0f;
	c2Circle ballCircle;
	ballCircle.p = c2V(150,160);
	ballCircle.r = 2;
	
#pragma region Game Drawings

	sprite background;
	background
		.origin_x(0)
		.bitmap("data/background.pix")
		;

#pragma region bricks

#pragma region row1

	c2v loc11 = c2V(62, 10);
	c2v loc12 = c2V(87, 10);
	c2v loc13 = c2V(112, 10);
	c2v loc14 = c2V(137, 10);
	c2v loc15 = c2V(162, 10);
	c2v loc16 = c2V(187, 10);
	c2v loc17 = c2V(212, 10);
	c2v loc18 = c2V(237, 10);

	sprite brick11;
	brick11
		.bitmap("data/brick.jpg")
		.position(62,10)
		;
	c2AABB brick11Collision;
	brick11Collision.min = c2V(loc11.x-13, loc11.y - 15);
	brick11Collision.max = c2V(loc11.x +20, loc11.y +5);

	sprite brick12;
	brick12
		.bitmap("data/brick.jpg")
		.position(87, 10)
		;
	c2AABB brick12Collision;
	brick12Collision.min = c2V(loc12.x-13, loc12.y-15);
	brick12Collision.max = c2V(loc12.x + 20, loc12.y + 5);

	sprite brick13;
	brick13
		.bitmap("data/brick.jpg")
		.position(112, 10)
		;
	c2AABB brick13Collision;
	brick13Collision.min = c2V(loc13.x-13, loc13.y-15);
	brick13Collision.max = c2V(loc13.x + 20, loc13.y + 5);

	sprite brick14;
	brick14
		.bitmap("data/brick.jpg")
		.position(137, 10)
		;
	c2AABB brick14Collision;
	brick14Collision.min = c2V(loc14.x-13, loc14.y-15);
	brick14Collision.max = c2V(loc14.x + 20, loc14.y + 5);

	sprite brick15;
	brick15
		.bitmap("data/brick.jpg")
		.position(162, 10)
		;
	c2AABB brick15Collision;
	brick15Collision.min = c2V(loc15.x-13, loc15.y - 15);
	brick15Collision.max = c2V(loc15.x + 20, loc15.y + 5);

	sprite brick16;
	brick16
		.bitmap("data/brick.jpg")
		.position(187, 10)
		;
	c2AABB brick16Collision;
	brick16Collision.min = c2V(loc16.x-13, loc16.y - 15);
	brick16Collision.max = c2V(loc16.x + 20, loc16.y + 5);

	sprite brick17;
	brick17
		.bitmap("data/brick.jpg")
		.position(212, 10)
		;
	c2AABB brick17Collision;
	brick17Collision.min = c2V(loc17.x-13, loc17.y - 15);
	brick17Collision.max = c2V(loc17.x + 20, loc17.y + 5);

	sprite brick18;
	brick18
		.bitmap("data/brick.jpg")
		.position(237, 10)
		;
	c2AABB brick18Collision;
	brick18Collision.min = c2V(loc18.x-13, loc18.y-15);
	brick18Collision.max = c2V(loc18.x + 20, loc18.y + 5);

#pragma endregion

#pragma region row2

	c2v loc21 = c2V(62, 25);
	c2v loc22 = c2V(87, 25);
	c2v loc23 = c2V(112, 25);
	c2v loc24 = c2V(137, 25);
	c2v loc25 = c2V(162, 25);
	c2v loc26 = c2V(187, 25);
	c2v loc27 = c2V(212, 25);
	c2v loc28 = c2V(237, 25);

	sprite brick21;
	brick21
		.bitmap("data/brick.jpg")
		.position(62,25)
		;
	c2AABB brick21Collision;
	brick21Collision.min = c2V(loc21.x-13, loc21.y-15);
	brick21Collision.max = c2V(loc21.x +20, loc21.y + 5);

	sprite brick22;
	brick22
		.bitmap("data/brick.jpg")
		.position(87, 25)
		;
	c2AABB brick22Collision;
	brick22Collision.min = c2V(loc22.x-13, loc22.y-15);
	brick22Collision.max = c2V(loc22.x + 20, loc22.y + 5);

	sprite brick23;
	brick23
		.bitmap("data/brick.jpg")
		.position(112, 25)
		;
	c2AABB brick23Collision;
	brick23Collision.min = c2V(loc23.x-13, loc23.y - 15);
	brick23Collision.max = c2V(loc23.x + 20, loc23.y + 5);

	sprite brick24;
	brick24
		.bitmap("data/brick.jpg")
		.position(137, 25)
		;
	c2AABB brick24Collision;
	brick24Collision.min = c2V(loc24.x-13, loc24.y - 15);
	brick24Collision.max = c2V(loc24.x + 20, loc24.y + 5);

	sprite brick25;
	brick25
		.bitmap("data/brick.jpg")
		.position(162, 25)
		;
	c2AABB brick25Collision;
	brick25Collision.min = c2V(loc25.x-13, loc25.y - 15);
	brick25Collision.max = c2V(loc25.x + 20, loc25.y + 5);

	sprite brick26;
	brick26
		.bitmap("data/brick.jpg")
		.position(187, 25)
		;
	c2AABB brick26Collision;
	brick26Collision.min = c2V(loc26.x-13, loc26.y - 15);
	brick26Collision.max = c2V(loc26.x + 20, loc26.y + 5);

	sprite brick27;
	brick27
		.bitmap("data/brick.jpg")
		.position(212, 25)
		;
	c2AABB brick27Collision;
	brick27Collision.min = c2V(loc27.x-13, loc27.y - 15);
	brick27Collision.max = c2V(loc27.x + 20, loc27.y + 5);

	sprite brick28;
	brick28
		.bitmap("data/brick.jpg")
		.position(237, 25)
		;
	c2AABB brick28Collision;
	brick28Collision.min = c2V(loc28.x-10, loc28.y);
	brick28Collision.max = c2V(loc28.x + 25, loc28.y + 5);

#pragma endregion

#pragma region row3

	c2v loc31 = c2V(62, 40);
	c2v loc32 = c2V(87, 40);
	c2v loc33 = c2V(112, 40);
	c2v loc34 = c2V(137, 40);
	c2v loc35 = c2V(162, 40);
	c2v loc36 = c2V(187, 40);
	c2v loc37 = c2V(212, 40);
	c2v loc38 = c2V(237, 40);

	sprite brick31;
	brick31
		.bitmap("data/brick.jpg")
		.position(62,40)
		;
	c2AABB brick31Collision;
	brick31Collision.min = c2V(loc31.x - 13, loc31.y -15);
	brick31Collision.max = c2V(loc31.x +20, loc31.y+5);

	sprite brick32;
	brick32
		.bitmap("data/brick.jpg")
		.position(87, 40)
		;
	c2AABB brick32Collision;
	brick32Collision.min = c2V(loc32.x-13, loc32.y-15);
	brick32Collision.max = c2V(loc32.x + 20, loc32.y + 5);

	sprite brick33;
	brick33
		.bitmap("data/brick.jpg")
		.position(112, 40)
		;
	c2AABB brick33Collision;
	brick33Collision.min = c2V(loc33.x-13, loc33.y-15);
	brick33Collision.max = c2V(loc33.x + 20, loc33.y + 5);

	sprite brick34;
	brick34
		.bitmap("data/brick.jpg")
		.position(137, 40)
		;
	c2AABB brick34Collision;
	brick34Collision.min = c2V(loc34.x-13, loc34.y-15);
	brick34Collision.max = c2V(loc34.x + 20, loc34.y + 5);

	sprite brick35;
	brick35
		.bitmap("data/brick.jpg")
		.position(162, 40)
		;
	c2AABB brick35Collision;
	brick35Collision.min = c2V(loc35.x-13, loc35.y-15);
	brick35Collision.max = c2V(loc35.x + 20, loc35.y + 5);

	sprite brick36;
	brick36
		.bitmap("data/brick.jpg")
		.position(187, 40)
		;
	c2AABB brick36Collision;
	brick36Collision.min = c2V(loc36.x-13, loc36.y-15);
	brick36Collision.max = c2V(loc36.x + 20, loc36.y + 5);

	sprite brick37;
	brick37
		.bitmap("data/brick.jpg")
		.position(212, 40)
		;
	c2AABB brick37Collision;
	brick37Collision.min = c2V(loc37.x-13, loc37.y-15);
	brick37Collision.max = c2V(loc37.x + 20, loc37.y + 5);

	sprite brick38;
	brick38
		.bitmap("data/brick.jpg")
		.position(237, 40)
		;
	c2AABB brick38Collision;
	brick38Collision.min = c2V(loc38.x-13, loc38.y-15);
	brick38Collision.max = c2V(loc38.x + 20, loc38.y + 5);

#pragma endregion

#pragma endregion 

	sprite paddle;
	paddle
		.bitmap("data/paddle.jpg")
		.position(140, 175)
		;

	
	sprite ball;
	ball
		.bitmap("data/ball.png")
		.position(150, 160)
		;

	label score;
	score
		.text("Score : 0")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(30.0f, 10.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(brightest_color())
		.outline(17)
		.bold(false)
		.shadow(0, 2.0f, 2.0f)
		;

	label lives;
	lives
		.text("Lives  : 0")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(290.0f, 10.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(brightest_color())
		.outline(17)
		.bold(false)
		.shadow(0, 2.0f, 2.0f)
		;

	label GameInstructions;
	GameInstructions
		.text("Press R to Realease the ball")
		.font("data/Volter__28Goldfish_29.fnt")
		.position(160.0f, 85.0f)
		.align(TEXT_ALIGN_CENTER)
		.color(darkest_color())
		.outline(17)
		.bold(true)
		.shadow(0, 2.0f, 2.0f)
		;

#pragma endregion

	while (is_running())
	{
		execute_frame();
		ShowCursor(false);

		score
			.text("Score : "+str(scoreValue))
			.font("data/Volter__28Goldfish_29.fnt")
			.position(30.0f, 10.0f)
			.align(TEXT_ALIGN_CENTER)
			.color(brightest_color())
			.outline(17)
			.bold(false)
			.shadow(0, 2.0f, 2.0f)
			;

		lives
			.text("Lives : " + str(livesCount))
			.font("data/Volter__28Goldfish_29.fnt")
			.position(290.0f, 10.0f)
			.align(TEXT_ALIGN_CENTER)
			.color(brightest_color())
			.outline(17)
			.bold(false)
			.shadow(0, 2.0f, 2.0f)
			;
	
		if (key_was_pressed(KEY_ESCAPE)) end(); // exit with no error
		if (key_was_pressed(KEY_RETURN)) fullscreen(!fullscreen());
		if (key_was_pressed(KEY_TAB)) crt_mode(!crt_mode());
		if (key_was_pressed(KEY_R)) //game starting key
		{
			isGameStarted = true;
			isMouseControl = true;
			GameInstructions.text("");
			ballYSpeed = -ballYSpeed;
			isPaddleCollide = true;
		}
		if (key_was_pressed(KEY_A)) //cheat for see the game won screen
		{
			Won_screen();
		}
		if (key_was_pressed(KEY_SPACE)) return 0;

		
#pragma region Paddle movement 


		//Keyboard movement
		if (key_is_down(KEY_LEFT))
		{
			xpos -= 2.0f;
			if (xpos < 0) xpos = 0.0f;
			isMouseControl = false;
		}
		else if (key_is_down(KEY_RIGHT))
		{
			xpos += 2.0f;
			if (xpos > 290) xpos = 290.0f;
			isMouseControl = false;
		}

		//when user using keyboard mouse combo this will enable mouse only mode
		if (key_was_released(KEY_LEFT))
		{
			tempPaddleXPos = mouse_x();
			isMouseControl = true;
		}
			
		if (key_was_released(KEY_RIGHT))
		{
			tempPaddleXPos = mouse_x();
			isMouseControl = true;
		}

		
		//mouse movement of the paddle used engine built function called mouse_x()
		if (isMouseControl && isGameStarted && tempPaddleXPos != mouse_x())
		{
			if (mouse_x() > 285)
			{
				xpos = 285;
			}
			else if (mouse_x()>=1 && mouse_x() <= 285)
			{
				xpos = mouse_x();
			}
		}

#pragma endregion

#pragma region ball movement
		if (isGameStarted)
		{
			if (isOnlyYAxis == true)
			{
				ballY += ballYSpeed*speedingFactor;
			}
			else
			{
				ballX += ballXSpeed*speedingFactor;
				ballY += ballYSpeed*speedingFactor;
			}

			
		}


		///ball debug code 

		///using mouse coordinates to operate the ball

		/*ballX = mouse_x();
		ballY = mouse_y();*/

		//use score and lives lables to display debug values. 
		/*score.text("X "+str(ballX));
		lives.text("Y "+ str(ballY));*/

		///using keyboard moving the ball
		/*if (key_is_down(KEY_A))
		{
			ballX -= ballXSpeed;
		}
		else if (key_is_down(KEY_D))
		{
			ballX += ballXSpeed;
		}
		else if (key_is_down(KEY_W))
		{
			ballY -= ballYSpeed;
		}
		else if (key_is_down(KEY_S))
		{
			ballY += ballYSpeed;
		}*/

#pragma endregion
	
		///checking ball exceeds the edges to bounce back
#pragma region checking ball limits

		if (ballX > ballXMax)
		{
			ballX = ballXMax;
			ballXSpeed = -ballXSpeed;
			isPaddleCollide = false;
			isOnlyYAxis = false;
		}
		else if (ballX < ballXMin)
		{
			ballX = ballXMin;
			ballXSpeed = -ballXSpeed;
			isPaddleCollide = false;
			isOnlyYAxis = false;
		}
		else if (ballY > ballYMax) //this case is one of the special cases ball touch the bottom
		{
			ballY = ballYMax;
			play_music("data/gunshot.wav");
			isPaddleCollide = false;
			livesCount--;
			ballY = 160;
			ballX = 150;
			xpos = 140;
			isGameStarted = false;
			ballXSpeed = 2.02f;
			ballYSpeed = 1.007f;
			isOnlyYAxis = false;

		}
		else if (ballY < ballYMin)
		{
			ballY = ballYMin;
			ballYSpeed = -ballYSpeed;
			isPaddleCollide = false;
			isOnlyYAxis = false;
		}
#pragma endregion

#pragma region Game Termination logics

		if (livesCount <= 0)
		{
			lives
				.text("Lives : " + str(livesCount))
				.font("data/Volter__28Goldfish_29.fnt")
				.position(290.0f, 10.0f)
				.align(TEXT_ALIGN_CENTER)
				.color(brightest_color())
				.outline(17)
				.bold(false)
				.shadow(0, 2.0f, 2.0f)
				;
			GameOver_screen();
		}

		if (scoreValue == 24)
		{
			Won_screen();
		}
#pragma endregion

		///checking Collision between bricks and ball / ball and paddle.

#pragma region Collision Check

		///bricks ball collisions 
#pragma region row collision

		if (c2CircletoAABB(ballCircle, brick11Collision))
		{
			brick11.visible(false);
			brick11Collision.min = c2V(-100, 0);
			brick11Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			play_music("data/coin.wav");
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick12Collision)) {
			brick12.visible(false);
			brick12Collision.min = c2V(-100, 0);
			brick12Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick13Collision)) {
			brick13.visible(false);
			brick13Collision.min = c2V(-100, 0);
			brick13Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.01f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick14Collision)) {
			brick14.visible(false);
			brick14Collision.min = c2V(-100, 0);
			brick14Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick15Collision)) {
			brick15.visible(false);
			brick15Collision.min = c2V(-100, 0);
			brick15Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick16Collision)) {
			brick16.visible(false);
			brick16Collision.min = c2V(-100, 0);
			brick16Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick17Collision)) {
			brick17.visible(false);
			brick17Collision.min = c2V(-100, 0);
			brick17Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick18Collision)) {
			brick18.visible(false);
			brick18Collision.min = c2V(-100, 0);
			brick18Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick21Collision)) {
			brick21.visible(false);
			brick21Collision.min = c2V(-100, 0);
			brick21Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick22Collision)) {
			brick22.visible(false);
			brick22Collision.min = c2V(-100, 0);
			brick22Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick23Collision)) {
			brick23.visible(false);
			brick23Collision.min = c2V(-100, 0);
			brick23Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick24Collision)) {
			brick24.visible(false);
			brick24Collision.min = c2V(-100, 0);
			brick24Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick25Collision)) {
			brick25.visible(false);
			brick25Collision.min = c2V(-100, 0);
			brick25Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick26Collision)) {
			brick26.visible(false);
			brick26Collision.min = c2V(-100, 0);
			brick26Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick27Collision)) {
			brick27.visible(false);
			brick27Collision.min = c2V(-100, 0);
			brick27Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick28Collision)) {
			brick28.visible(false);
			brick28Collision.min = c2V(-100, 0);
			brick28Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			scoreValue++;
			isPaddleCollide = false;
			play_music("data/coin.wav");
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick31Collision)) {
			brick31.visible(false);
			brick31Collision.min = c2V(-100, 0);
			brick31Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			pause_music();
			play_music("data/coin.wav");
			resume_music();
			scoreValue++;
			isPaddleCollide = false;
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick32Collision)) {
			brick32.visible(false);
			brick32Collision.min = c2V(-100, 0);
			brick32Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			pause_music();
			play_music("data/coin.wav");
			resume_music();
			scoreValue++;
			isPaddleCollide = false;
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick33Collision)) {
			brick33.visible(false);
			brick33Collision.min = c2V(-100, 0);
			brick33Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			pause_music();
			play_music("data/coin.wav");
			resume_music();
			scoreValue++;
			isPaddleCollide = false;
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick34Collision)) {
			brick34.visible(false);
			brick34Collision.min = c2V(-100, 0);
			brick34Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			pause_music();
			play_music("data/coin.wav");
			resume_music();
			scoreValue++;
			isPaddleCollide = false;
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick35Collision)) {
			brick35.visible(false);
			brick35Collision.min = c2V(-100, 0);
			brick35Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			pause_music();
			play_music("data/coin.wav");
			resume_music();
			scoreValue++;
			isPaddleCollide = false;
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick36Collision)) {
			brick36.visible(false);
			brick36Collision.min = c2V(-100, 0);
			brick36Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			pause_music();
			play_music("data/coin.wav");
			resume_music();
			scoreValue++;
			isPaddleCollide = false;
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick37Collision)) {
			brick37.visible(false);
			brick37Collision.min = c2V(-100, 0);
			brick37Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			pause_music();
			play_music("data/coin.wav");
			resume_music();
			scoreValue++;
			isPaddleCollide = false;
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}
		else if (c2CircletoAABB(ballCircle, brick38Collision)) {
			brick38.visible(false);
			brick38Collision.min = c2V(-100, 0);
			brick38Collision.max = c2V(-100, 0);
			ballXSpeed = -ballXSpeed;
			ballYSpeed = -ballYSpeed;
			pause_music();
			play_music("data/coin.wav");
			resume_music();
			scoreValue++;
			isPaddleCollide = false;
			speedingFactor = speedingFactor + 0.05f;
			isOnlyYAxis = false;
		}

#pragma endregion
		
		///Paddle ball collision
		if (c2CircletoAABB(ballCircle, paddleCollision) && isPaddleCollide == false && isGameStarted)
		{
			play_music("data/coin.wav");

			///this section will devide the paddle into three sections are treat differently when it collide with the ball
			///left most part will push the ball into the left direction 
			///right most part will puch the ball into the right direction while middle point will be bounce back the ball straight
			if (ballX >= paddleCollision.min.x && ballX < paddleCollision.min.x+20)
			{
				if (ballXSpeed > 0)
				{
					ballXSpeed = -ballXSpeed;
				}
				ballYSpeed = -ballYSpeed;
			}
			else if (ballX <= paddleCollision.max.x && ballX > paddleCollision.max.x-20)
			{
				if (ballXSpeed < 0)
				{
					ballXSpeed = -ballXSpeed;
				}
				ballYSpeed = -ballYSpeed;
			}
			else if (ballX >= paddleCollision.min.x +20 && ballX <= paddleCollision.max.x-20 )
			{
				ballYSpeed = -ballYSpeed;
				isOnlyYAxis = true;
			}
			
			isPaddleCollide = true;
		}

#pragma endregion

		///paddle movement and collider movement
		///since collider and pixie use different coordinate system need to add some value to get to the precious point
		paddle.position(xpos,175);
		paddleCollision.min = c2V(xpos-15, 160);
		paddleCollision.max = c2V(xpos+35, 180);

		///ball movement and ball collider movement, since collision system and pixie coordinate systems are different
		///need to normalize the coordinates.
		ball.position(ballX, ballY);

		if (ballX < 160)
		{
			ballXCollision = ballX / 160 * 200 - 200;
		}
		else
		{
			ballXCollision = (ballX) / 160 * 200 - 200;
		}

		if (ballY < 100)
		{
			ballYCollision = ballY / 100 * -100 + 100;
		}
		else
		{
			ballYCollision = ((ballY - 101) * 99)*-100;
		}
		ballCircle.p = c2V(ballX, ballY);
	}
	return 0;
	}

