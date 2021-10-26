#pragma once
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int SCREEN_FPS = 90;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

const int BALL_WIDTH = 20;
const int BALL_HEIGHT = 20;
const int BALL_VEL = 4;

const int PADDLE_HEIGHT = 85;
const int PADDLE_WIDTH = 20;
const int PADDLE_VEL = 3;
const int LPADDLEX = 30;
const int RPADDLEX = SCREEN_WIDTH - PADDLE_WIDTH - LPADDLEX; // edge of screen minus the width of the paddle minus the width from the paddle to edge of screen

