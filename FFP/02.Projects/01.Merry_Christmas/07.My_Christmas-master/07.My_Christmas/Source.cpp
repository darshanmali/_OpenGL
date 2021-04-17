#include<windows.h>
#include"Header.h"
#include<gl/GL.h>
#include<time.h>
#include<stdio.h>
#include<gl/GLU.h>

#define _USE_MATH_DEFINES
#include<math.h>

#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"Glu32.lib")
#pragma comment(lib,"Winmm.lib")

#define WIN_WIDTH_DM 800
#define WIN_HEIGHT_DM 600

//Global Fuction 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


//*********************************************************** Land & Sky *************************************************************
//Land And Sky Globle Variables
GLuint Tree_Texture;
GLuint Leaf_Texture;
GLuint Sky_Texture;
GLuint Grass_Texture;


//*********************************************************** House *************************************************************
//House Globle Variables
GLuint Wood_Texture;
GLuint Snow_Texture;
GLuint Boarder_Texture;
GLuint Door_Texture;
GLuint Steel_Texture;
GLuint Black_Glass_Texture;
GLuint Glass_Texture;
GLuint Tree_Glass_Texture;
GLfloat Door_angle = 0.0f;

bool Black_Left = false;
bool Black_Front_Left = false;

bool Black_Right = false;
bool Black_Front_right = false;

bool Black_Back_Left = false;
bool Black_Back_Right = false;


bool Close_Door = false;

//Bushes
GLuint Light_Green;
GLuint Dim_Green;
GLuint Dark_Green;

//Tree
GLuint tree_Trunk;
GLuint tree_Light_Green;
GLuint tree_Dim_Green;
GLuint tree_Dark_Green;

//*********************************************************** Girl *************************************************************
//**************One********Texture Variables
GLuint girl_Texture;
GLuint girl_Face_Texture;
GLuint Girls_Foots_Texture;
GLuint Girls_Foot_Down_Texture;
GLuint Girls_Nose_Texture;

//*************Two*************Transformation variables

GLfloat girl_Main_Body_angle = 180.0f;

GLfloat girl_sholder_Left = 134.0f;
GLfloat girl_Lbow_Left = 217.0f;

GLfloat girl_sholder_Right = 134.0f;
GLfloat girl_Lbow_Right = 217.0f;

GLfloat girl_Lbow_Bending = 80.0f;

GLfloat girl_Thigh_Right = 70;
GLfloat girl_Calf_Right = 90;

GLfloat girl_Thigh_Left = 70;
GLfloat girl_Calf_Left = 90;

GLfloat girl_Model_X = -1.5f;
GLfloat girl_Model_Y = 0.8f;
GLfloat girl_Model_Z = -4.75f;

GLfloat eye_x = 0.0f;
GLfloat eye_y = 0.0f;
GLfloat eye_z = 2.0f;

bool girl_Restor_Position = false; 
bool girl_Rotating_Position = false;
bool girl_Walking = false;
bool girl_Door_Opening = false;
bool Door_Motion = false;
bool girl_Animation = false;

bool move_Front_Right = true;
bool move_Back_Right = false;

bool move_Front_Left = false;
bool move_Back_Left = true;

bool start_walking = false;

//*********************************************************** Santa *************************************************************

//**************One********Texture Variables
GLuint Santa_Texture;
GLuint Santa_Foots_Texture;
GLuint Santa_Face_Texture;

//*************Two*************Transformation variables
GLfloat santa_sholder_Left = 180;
GLfloat santa_Lbow_Left = 355;

GLfloat santa_sholder_Right = 180;
GLfloat santa_Lbow_Right = 350;

GLfloat santa_Thigh_Right = 180;
GLfloat santa_Calf_Right = 5;

GLfloat santa_Thigh_Left = 180;
GLfloat santa_Calf_Left = 5;

bool santa_walk = false;
bool santa_Restore = false;
bool Move_Santa_and_Ferrari = false;
bool Santa_Front_Walking = false;

bool move_Front_Right_s = true;
bool move_Back_Right_s = false;

bool move_Front_Left_s = false;
bool move_Back_Left_s = true;
bool Santa_Bring_Gift = false;

//Santa Model
GLfloat santa_Model_X = 40.0f;
GLfloat santa_Model_Y = 1.2f;
GLfloat santa_Model_Z = 15.0f;

GLfloat Santa_Rotation = 90.0f;
GLfloat angle_gift = 315.0f;

// Santa Ferrari
GLfloat Santa_Ferrari_Model_X = 40.0f;
GLfloat Santa_Ferrari_Model_Y = 0.15f;
GLfloat Santa_Ferrari_Model_Z = 15.0f;

//*********************************************************** Birld *************************************************************
//Bird
GLuint Bird_Texture;
GLuint Bird_Bill_Texture;
GLuint Nest_Texture;

//*********************************************************** Snow *************************************************************
//Snow
int rand_val[10];
int rand_val_2[10];
int rand_val_3[10];
int rand_val_4[10];

GLfloat snow_angle = 0.0f;

// Snow Lights
bool gbLight = false;
GLfloat lAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat lDefues[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat lPosition[] = { -10.0f, -10.0f, 50.0f, 1.0f };
GLfloat lights_Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat material_Ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat material_Diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat material_Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat material_Shininess = 20.0f;

//Font Light
GLfloat flAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat flDefues[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat flPosition[] = { 70.0f, 60.0f, 80.0f, 1.0f };
GLfloat flights_Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat fmaterial_Ambient[] = { 0.6f, 0.5f, 1.0f, 1.0f };
GLfloat fmaterial_Diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat fmaterial_Specular[] = { 1.0f, 0.0f, 0.5f, 1.0f };

GLfloat fmaterial_Shininess = 60.0f;

//*********************************************************** Data Structure *************************************************************
//Data structure for Snow
struct Snow
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    struct Snow* Next = NULL;

}*Front = NULL, * Rear = NULL;
struct Snow* Front_2 = NULL, * Rear_2 = NULL;
struct Snow* Front_3 = NULL, * Rear_3 = NULL;
struct Snow* Front_4 = NULL, * Rear_4 = NULL;

GLfloat snow_fall_1 = 20.0f;
GLfloat snow_fall_2 = 20.0f;
GLfloat snow_fall_3 = 20.0f;
GLfloat snow_fall_4 = 20.0f;

bool start_snow_fall = false;
bool snow_flag_1 = true;
bool snow_flag_2 = false;
bool snow_flag_3 = false;
bool snow_flag_4 = false;

//Snow Function 
struct Snow* CreateNode(void);
void InsertData(int[], int);


//***********************************************************  Gift *************************************************************
GLuint Gift_Texture;
GLfloat Gift_Model_X = 41.5f;
GLfloat Gift_Model_Y = 1.0f;
GLfloat Gift_Model_Z = 15.0f;

//*********************************************************** Camera Variables*************************************************************
//Camera 
GLfloat Camera_Position_X = -40.0f;
GLfloat Camera_Position_Y = 10.0f;
GLfloat Camera_Position_Z = 35.0f;
GLfloat Camera_Eye_X = 0.0f;
GLfloat Camera_Eye_Y = -30.0f;
GLfloat Camera_Eye_Z = 0.0f;


GLfloat Camera_Position_X_Increment = 0.0f;
GLfloat Camera_Position_Y_Increment = 0.0f;
GLfloat Camera_Position_Z_Increment = 0.0f;
GLfloat Camera_Eye_X_Increment = 0.0f;
GLfloat Camera_Eye_Y_Increment = 0.0f;
GLfloat Camera_Eye_Z_Increment = 0.0f;

bool  part_1 = true;
bool  part_2 = false;
bool  part_3 = false;
bool  part_4 = false;
bool  part_5 = false;
bool  part_6 = false;


bool Camera_Move = false;

//*********************************************************** Font Use *************************************************************
//Font variables
HFONT myFont;
HINSTANCE   hInstance;
GLuint  base;
GLYPHMETRICSFLOAT gmf[256];
GLfloat Font_X = -3.25f;
GLfloat Font_Y = 0.0f;
GLfloat Font_Z = -5.0f;
GLfloat incre = 3.0f;
GLfloat sin_y = 10.0f;
GLfloat sin_Fix_val = 0.2f;
GLuint char_count = 0;
GLfloat Print_ = true;
bool Animate = false;
GLfloat X_for_present = -10.0f;

//printting values
bool Print_A = true;
bool Print_S = false;
bool Print_T = false;
bool Print_R = false;
bool Print_O = false;

bool Print_M = false;
bool Print_E = false;
bool Print_D = false;
bool Print_I = false;

bool Print_C = false;
bool Print_CO = false;
bool Print_CM = false;
bool Print_P = false;

bool Stick_S = false;
bool Stick_T = false;
bool Stick_R = false;
bool Stick_O = false;

bool Stick_M = false;
bool Stick_E = false;
bool Stick_D = false;
bool Stick_I = false;

bool Stick_C = false;
bool Stick_CO = false;
bool Stick_CM = false;
bool Stick_P = false;

GLfloat f_fade_in_x = 1.0f;
GLfloat f_fade_in_y = 1.0f;
GLfloat f_fade_in_z = 1.0f;



TCHAR comicFontName[] = TEXT("Comic Sans MS");

//void Display_For_Font(void);
GLvoid Print_Font(const char*, ...);
GLvoid KillFont(GLvoid);
HFONT BuildFont(TCHAR*);
void SelectFont(HFONT);


//*********************************************************** Global Use *************************************************************
//Global Variables
HBITMAP hBitmap;
BITMAP bmp;
DWORD dwStyle_D;
WINDOWPLACEMENT wpPrev_DM = { sizeof(WINDOWPLACEMENT) };
bool gdFullScreen_DM = false;
HWND ghwnd_DM = NULL;
bool gbActiveWindows_DM = false;
HDC ghdc_DM = NULL;
HGLRC ghrc_DM = NULL;
FILE* gpFile_DM = NULL;
GLfloat angle = 0.0f;

//printing state
bool print = true;

//Fog Variables
GLfloat fogColor[4] = { 0.5f,0.5f,0.5f,1.0f };

GLUquadric* quadric = NULL;

//Global Fade In Out variables
GLfloat gl_fade_x = 0.0f;
GLfloat gl_fade_y = 0.0f;
GLfloat gl_fade_z = 0.0f;

//States for the Animation
bool bStart_Font = false;
bool bStart_Animation = false;

//End font variables
bool bStart_End = false;
GLfloat incre_End_Thanks = -7.0f;


bool fade_in_christmas_Scene = false;
bool fade_out_christmas_Scene = false;

bool play_Christmas_Sound = false;

//Sound Effects
bool Sound_1 = true;


void Fade_In_Out(void);



//Globle Function 
void Resize(int, int);
void unInitialize(void);
void Display(void);
void ToggelFullScreen(void);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreIntance, LPSTR lpszCmdLine, int iCmdShow)
{
    //Variable Declaration
    WNDCLASSEX wndclassex;
    HWND hwnd;
    MSG msg;
    TCHAR Appname[] = TEXT("MY_SAMPLE");
    bool bDone = false;
    INT x = 0, y = 0;
    INT Width = 800;
    INT Height = 600;
    MONITORINFO mi_D = { sizeof(MONITORINFO) };
    
    //Function Declaration
    void Initialize(void);
    
    if (fopen_s(&gpFile_DM, "log.txt", "w"))
    {
        MessageBox(NULL, TEXT(" File Can Not Created!"), TEXT("Error"), MB_OK);
    }


    wndclassex.cbSize = sizeof(WNDCLASSEX);
    wndclassex.cbClsExtra = 0;
    wndclassex.cbWndExtra = 0;
    wndclassex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wndclassex.lpszClassName = Appname;
    wndclassex.lpfnWndProc = WndProc;
    wndclassex.lpszMenuName = NULL;
    wndclassex.hInstance = hInstance;
    wndclassex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
    wndclassex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
    wndclassex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClassEx(&wndclassex);

    x = GetSystemMetrics(SM_CXSCREEN);
    y = GetSystemMetrics(SM_CYSCREEN);

    hwnd = CreateWindowEx(WS_EX_APPWINDOW,
        Appname,
        TEXT("My Christmas !"),
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
        (x / 2) - (Width / 2),
        (y / 2) - (Height / 2),
        Width,
        Height,
        NULL,
        NULL,
        hInstance,
        NULL);

    ghwnd_DM = hwnd;


    ShowWindow(hwnd, iCmdShow);
    SetForegroundWindow(hwnd);
    SetFocus(hwnd);


    Initialize();


    while (bDone == false)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                bDone = true;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            if (bool gbActiveWindow = true)
            {
                // Here You should call Update Fuction for openGl Redering

               // Here You should call Display Fuction for openGl Redering

                Display();
            }
        }

    }

    return(msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    switch (iMsg)
    {

    case WM_PAINT:
        
        if (!gdFullScreen_DM)
        {
            ToggelFullScreen();
            gdFullScreen_DM = true;
        }
        
        break;

    case WM_SETFOCUS:
        gbActiveWindows_DM = true;
        break;
    case WM_KILLFOCUS:
        gbActiveWindows_DM = false;
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_SPACE:
            bStart_Font = true;

            break;
        case 'E':
            fade_out_christmas_Scene = true;
            break;
        case 'W':
            girl_Walking = true;
            break;
        case 'O':
            girl_Door_Opening = true;
            girl_Animation = true;
            break;
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;
        case 0x46:
        case 0x66:
            ToggelFullScreen();
            break;
        default:
            break;
        }
        break;
    case WM_SIZE:
        Resize(LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        unInitialize();
        PostQuitMessage(0);
        break;
    }

    return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggelFullScreen()
{
    //Local Variable Declare
    MONITORINFO mi_D = { sizeof(MONITORINFO) };

    dwStyle_D = GetWindowLong(ghwnd_DM, GWL_STYLE);
    if (GetWindowPlacement(ghwnd_DM, &wpPrev_DM) && GetMonitorInfo(MonitorFromWindow(ghwnd_DM, MONITORINFOF_PRIMARY), &mi_D))
    {
        SetWindowLong(ghwnd_DM, GWL_STYLE, (dwStyle_D & ~WS_OVERLAPPEDWINDOW));
        SetWindowPos(ghwnd_DM, HWND_TOP, mi_D.rcMonitor.left, mi_D.rcMonitor.top, mi_D.rcMonitor.right - mi_D.rcMonitor.left, mi_D.rcMonitor.bottom - mi_D.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED); // SWP_FRAMECHANGED = WM_NCCALCSIZE      
    }

    ShowCursor(FALSE);

}

void Initialize()
{
    PIXELFORMATDESCRIPTOR pfd_DM;
    int iPixelFormatIndex_DM;


    bool LoadGLTexture(GLuint*, TCHAR[]);


    ghdc_DM = GetDC(ghwnd_DM);

    ZeroMemory(&pfd_DM, sizeof(PIXELFORMATDESCRIPTOR));

    pfd_DM.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd_DM.nVersion = 1;
    pfd_DM.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd_DM.iPixelType = PFD_TYPE_RGBA;
    pfd_DM.cColorBits = 32;
   
    pfd_DM.cDepthBits = 32;
    pfd_DM.cRedBits = 8;
    pfd_DM.cGreenBits = 8;
    pfd_DM.cBlueBits = 8;
    pfd_DM.cAlphaBits = 8;


    iPixelFormatIndex_DM = ChoosePixelFormat(ghdc_DM, &pfd_DM);

    if (iPixelFormatIndex_DM == 0)
    {
        fprintf_s(gpFile_DM, "ChoosePixelFormat faild.\n");
        DestroyWindow(ghwnd_DM);
    }

    if (SetPixelFormat(ghdc_DM, iPixelFormatIndex_DM, &pfd_DM) == FALSE)
    {
        fprintf_s(gpFile_DM, "SetPixelFormat Faild.\n");
        DestroyWindow(ghwnd_DM);
    }

    ghrc_DM = wglCreateContext(ghdc_DM);
    if (ghdc_DM == NULL)
    {
        fprintf_s(gpFile_DM, "wglCreateContext() Faild.\n");
        DestroyWindow(ghwnd_DM);
    }

    if (wglMakeCurrent(ghdc_DM, ghrc_DM) == FALSE)
    {
        fprintf_s(gpFile_DM, "wglMakeCurrent() Faild.\n");
        DestroyWindow(ghwnd_DM);
    }


    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);



    //**************************************Part One *****************************************
    //Sky
    LoadGLTexture(&Sky_Texture, MAKEINTRESOURCE(MYSKY));

    //Land
    LoadGLTexture(&Grass_Texture, MAKEINTRESOURCE(MYGRASS));
    
    //Tree
    LoadGLTexture(&Tree_Texture, MAKEINTRESOURCE(MYTREE));
    
    
    LoadGLTexture(&Leaf_Texture, MAKEINTRESOURCE(MYTREE_LEAF));
    
    
    //**************************************Part Two *****************************************
    //House
    LoadGLTexture(&Wood_Texture, MAKEINTRESOURCE(MYWOOD));
    LoadGLTexture(&Snow_Texture, MAKEINTRESOURCE(MYSNOW));
    LoadGLTexture(&Boarder_Texture, MAKEINTRESOURCE(MYBOARDER));
    LoadGLTexture(&Door_Texture, MAKEINTRESOURCE(MYDOOR));
    LoadGLTexture(&Steel_Texture, MAKEINTRESOURCE(MYSTEEL));
    LoadGLTexture(&Glass_Texture, MAKEINTRESOURCE(MYGLASS));
    LoadGLTexture(&Black_Glass_Texture, MAKEINTRESOURCE(MYBLACKGLASS));
    LoadGLTexture(&Tree_Glass_Texture, MAKEINTRESOURCE(MYTREEGLASS));

    //Bushes
    LoadGLTexture(&Light_Green, MAKEINTRESOURCE(GREEN_LIGHT));
    LoadGLTexture(&Dim_Green, MAKEINTRESOURCE(GREEN_DIM));
    LoadGLTexture(&Dark_Green, MAKEINTRESOURCE(GREEN_DARK));

    //tree
    LoadGLTexture(&tree_Light_Green, MAKEINTRESOURCE(TREE_GREEN_LIGHT));
    LoadGLTexture(&tree_Dim_Green, MAKEINTRESOURCE(TREE_GREEN_DIM));
    LoadGLTexture(&tree_Dark_Green, MAKEINTRESOURCE(TREE_GREEN_DARK));
    LoadGLTexture(&tree_Trunk, MAKEINTRESOURCE(TREE_TRUNK));
    
    //**************************************Part Three *****************************************
    //Girl
    LoadGLTexture(&girl_Texture, MAKEINTRESOURCE(MYCLOTHS));
    LoadGLTexture(&Girls_Foots_Texture, MAKEINTRESOURCE(MYFOOTS));
    LoadGLTexture(&Girls_Foot_Down_Texture, MAKEINTRESOURCE(MYSHOOSE));
    LoadGLTexture(&girl_Face_Texture, MAKEINTRESOURCE(MYFACE));
    LoadGLTexture(&Girls_Nose_Texture, MAKEINTRESOURCE(MYNOSE));

    //**************************************Part Four *****************************************
    //Santa
    LoadGLTexture(&Santa_Texture, MAKEINTRESOURCE(MYSANTA));
    LoadGLTexture(&Santa_Foots_Texture, MAKEINTRESOURCE(MYSANTAFOOT));
    LoadGLTexture(&Santa_Face_Texture, MAKEINTRESOURCE(MYSANTAFACE));

    //**************************************Part Five *****************************************
    //Birld
    LoadGLTexture(&Bird_Texture, MAKEINTRESOURCE(MYBIRD));
    LoadGLTexture(&Bird_Bill_Texture, MAKEINTRESOURCE(MYBILL));
    LoadGLTexture(&Nest_Texture, MAKEINTRESOURCE(MYNEST));

    //**************************************Part Six *****************************************
    //Snow
    
    //Lights
    glLightfv(GL_LIGHT0, GL_AMBIENT, lAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lDefues);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lights_Specular);
    glLightfv(GL_LIGHT0, GL_POSITION, lPosition);

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_Specular);

    glMaterialf(GL_FRONT, GL_SHININESS, material_Shininess);

    //Lights
    glLightfv(GL_LIGHT1, GL_AMBIENT, flAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, flDefues);
    glLightfv(GL_LIGHT1, GL_SPECULAR, flights_Specular);
    glLightfv(GL_LIGHT1, GL_POSITION, flPosition);

    glMaterialfv(GL_FRONT, GL_AMBIENT, fmaterial_Ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, fmaterial_Diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, fmaterial_Specular);

    glMaterialf(GL_FRONT, GL_SHININESS, fmaterial_Shininess);


    //**************************************Part Seven *****************************************
    //fog 
    glFogi(GL_FOG_MODE, GL_EXP2);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_DENSITY, 0.025f);
    glHint(GL_FOG_HINT, GL_NICEST);
    glFogf(GL_FOG_START, 0.0f);
    glFogf(GL_FOG_END, 5.0f);
    if (print)
        glEnable(GL_FOG);
    else
        glDisable(GL_FOG);
    //**************************************Part Eight *****************************************
    LoadGLTexture(&Gift_Texture, MAKEINTRESOURCE(MYGIFT));
    
    //**************************************Part Font *****************************************
    myFont = BuildFont(comicFontName);
    SelectFont(myFont);

    //rand 1
    int j = 0;
    while (j < 10)
    {
        rand_val[j] = 1 - rand() % 10;
        j++;
    }

    //rand 2
    srand(2);
    j = 0;
    while (j < 10)
    {
        rand_val_2[j] = (rand() % 10) - 2;
        j++;
    }

    //rand 3
    srand(5);
    j = 0;
    while (j < 10)
    {
        rand_val_3[j] = (rand() % 10) - 3;
        j++;
    }

    //rand 4
    srand(1);
    j = 0;
    while (j < 10)
    {
        rand_val_4[j] = (rand() % 10);
        j++;
    }

    //Queue Implematation 1 Front
    InsertData(rand_val, 1);

    //Queue Implematation 2 Front
    InsertData(rand_val_2, 2);

    //Queue Implematation 3 Front
    InsertData(rand_val_3, 3);

    //Queue Implematation 4 Front
    InsertData(rand_val_4, 4);
    
    Resize(WIN_WIDTH_DM, WIN_HEIGHT_DM);
}

//Font Function
HFONT BuildFont(TCHAR* fontName)                    // Build Our Bitmap Font
{
    HFONT font;
    base = glGenLists(256);                 // Storage For 256 Characters
    font = CreateFont(-12,                  // Height Of Font
        0,                                  // Width Of Font
        0,                                  // Angle Of Escapement
        0,                                  // Orientation Angle
        0,                                  // Font Weight
        FALSE,                              // Italic
        FALSE,                              // Underline
        FALSE,                              // Strikeout
        ANSI_CHARSET,                       // Character Set Identifier
        OUT_TT_PRECIS,                      // Output Precision
        CLIP_DEFAULT_PRECIS,                // Clipping Precision
        ANTIALIASED_QUALITY,                // Output Quality
        FF_DONTCARE | DEFAULT_PITCH,        // Family And Pitch
        fontName);					// Font Name
    return(font);
}

void SelectFont(HFONT hFont)
{
    SelectObject(ghdc_DM, hFont);
    wglUseFontOutlines(ghdc_DM,             // Select The Current DC
        0,                                  // Starting Character
        255,                                // Number Of Display Lists To Build
        base,                               // Starting Display Lists
        0.0f,                               // Deviation From The True Outlines
        0.1f,                              // Font Thickness In The Z Direction
        WGL_FONT_POLYGONS,                  // Use Polygons, Not Lines
        gmf);                               // Address Of Buffer To Recieve Data

}

bool LoadGLTexture(GLuint* Texture, TCHAR Resource_ID[])
{
    bool bResult = false;

    hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), Resource_ID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
    if (hBitmap != NULL)
    {
        bResult = true;
        GetObject(hBitmap, sizeof(BITMAP), &bmp);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
        glGenTextures(1, Texture);
        glBindTexture(GL_TEXTURE_2D, *Texture);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);
        DeleteObject(hBitmap);
    }
    return (bResult);
}

struct Snow* CreateNode()
{
    struct Snow* Temp = NULL;
    Temp = (struct Snow*)malloc(sizeof(struct Snow));
    return (Temp);

}

void InsertData(int data[], int flag)
{
    struct Snow* Temp = NULL, * Node = NULL;
    int i = 0;
    Node = CreateNode();
    Node->x = (GLfloat)data[0] - 1;
    Node->y = (GLfloat)data[0];
    Node->z = (GLfloat)data[0];
    Node->Next = NULL;
    i = 1;

    Temp = Node;
    switch (flag)
    {
        //rand_val
    case 1:
        if (Front == NULL && Rear == NULL)
        {
            Front = Temp;
            Rear = Temp;
        }
        while (i < 10)
        {

            Node = CreateNode();

            Node->x = (GLfloat)data[i];
            Node->y = (GLfloat)rand_val_4[i] - 2.0f;
            Node->z = (GLfloat)data[i];
            Node->Next = Temp;

            Front = Node;
            Temp = Node;
            i++;

        }

        break;
        //rand_val_2
    case 2:
        if (Front_2 == NULL && Rear_2 == NULL)
        {
            Front_2 = Temp;
            Rear_2 = Temp;
        }
        while (i < 10)
        {

            Node = CreateNode();

            Node->x = (GLfloat)data[i];
            Node->y = (GLfloat)rand_val_4[i] - 1.0f;
            Node->z = (GLfloat)data[i];
            Node->Next = Temp;

            Front_2 = Node;
            Temp = Node;
            i++;

        }

        break;

        //rand_val_3
    case 3:
        if (Front_3 == NULL && Rear_3 == NULL)
        {
            Front_3 = Temp;
            Rear_3 = Temp;
        }
        while (i < 10)
        {

            Node = CreateNode();

            Node->x = (GLfloat)data[i];
            Node->y = (GLfloat)rand_val_4[i] - 1.5f;
            Node->z = (GLfloat)data[i];
            Node->Next = Temp;

            Front_3 = Node;
            Temp = Node;
            i++;

        }

        break;
        //rand_val_4
    case 4:
        if (Front_3 == NULL && Rear_3 == NULL)
        {
            Front_3 = Temp;
            Rear_3 = Temp;
        }
        while (i < 10)
        {

            Node = CreateNode();

            Node->x = (GLfloat)data[i];
            Node->y = (GLfloat)rand_val_4[i] - 2.5f;
            Node->z = (GLfloat)data[i];
            Node->Next = Temp;

            Front_4 = Node;
            Temp = Node;
            i++;

        }

        break;
    default:
        break;
    }

}

void Resize(int width, int height)
{
    if (height == 0)
    {
        height = 1;
    }

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(44.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);


}

void Display()
{
    //Local Fuction Declaration Part 1
    void Tree(void);
    void Sky(void);
    void Land(void);

    //Local Function Declaration Part 2
    void House(void);
    void Bushes(void);
    void House_Tree(void);

    //Local Function Declaration Part 3
    void Girl(void);
    void Restore_update_girl(void);
    void Rotating_update_girl(void);
    void Walking_update_girl(void);
    void Door_Opening(void);
    void Door_Opening_girl_Animation(void);

    //Local Function Declaration Part 4
    void Santa(void);
    void Santa_Ferrari(void);
    void Walking_Santa(void);
    void Restore_Santa(void);
    void Transform_Santa_Ferrari(void);
    void Santa_Bringing_Gift(void);
    
    //Local Function Declaration Part 5
    void Bird(void);

    //Local Function Declaration Part 6
    void Snow(void);

    //Local Function Declaration Part 7
    void Mountain(void);

    //Local Function Declaration Part 8
    void Gift(void);

    //Local Function For Camera part 9
    void Camera_update(void);

    //Local Function For Font 
    void Font_update(void);

    //Code Began
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if (bStart_Font)
    {

        glPushMatrix();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        glColor3f(f_fade_in_x, f_fade_in_y, f_fade_in_z);

        glPushMatrix();

        glEnable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        glBindTexture(GL_TEXTURE_2D, Sky_Texture);
        glBegin(GL_QUADS);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(5.0f, 4.0f, -6.0f);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-5.0f, 4.0f, -6.0f);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-5.0f, -4.0f, -6.0f);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(5.0f, -4.0f, -6.0f);

        glEnd();
        glDisable(GL_TEXTURE_2D);
        
        glPopMatrix();

        glPushMatrix();
        
        glEnable(GL_LIGHT1);
        glEnable(GL_LIGHTING);




        if (Print_A)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
                //if (Sound_1)
                //{
                //    PlaySoundW(MAKEINTRESOURCE(MYDROP), GetModuleHandleA(NULL), SND_RESOURCE | SND_ASYNC);
                //    Sound_1 = false;
                //}
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            Print_Font("A");
        }
        else
        {
            glPushMatrix();
            glTranslatef(-3.25f, 0.0f, -5.0f);
            Print_Font("A");
            glPopMatrix();
            
            
        }

        if (Print_S)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(0.5f, 0.0f, 0.0f);
            Print_Font("S");

        }
        if(!Print_S && Stick_S)
        {
            glPushMatrix();
            glTranslatef(-2.75f, 0.0f, -5.0f);
            Print_Font("S");
            glPopMatrix();
        }
        
        if (Print_T)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font("T");
        }
        if (!Print_T && Stick_T)
        {
            glPushMatrix();
            glTranslatef(-2.25f, 0.0f, -5.0f);
            Print_Font("T");
            glPopMatrix();
        }

        if (Print_R)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(1.5f, 0.0f, 0.0f);
            Print_Font("R");
        }
        if (!Print_R && Stick_R)
        {
            glPushMatrix();
            glTranslatef(-1.75f, 0.0f, -5.0f);
            Print_Font("R");
            glPopMatrix();
        }

        if (Print_O)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(2.0f, 0.0f, 0.0f);
            Print_Font("O");
        }
        if (!Print_O && Stick_O)
        {
            glPushMatrix();
            glTranslatef(-1.25f, 0.0f, -5.0f);
            Print_Font("O");
            glPopMatrix();
        }

        if (Print_M)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(2.5f, 0.0f, 0.0f);
            Print_Font("M");
        }
        if (!Print_M && Stick_M)
        {
            glPushMatrix();
            glTranslatef(-0.75f, 0.0f, -5.0f);
            Print_Font("M");
            glPopMatrix();
        }

        if (Print_E)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(3.1f, 0.0f, 0.0f);
            Print_Font("E");
        }
        if (!Print_E && Stick_E)
        {
            glPushMatrix();
            glTranslatef(-0.15f, 0.0f, -5.0f);
            Print_Font("E");
            glPopMatrix();
        }

        if (Print_D)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(3.5f, 0.0f, 0.0f);
            Print_Font("D");
        }
        if (!Print_D && Stick_D)
        {
            glPushMatrix();
            glTranslatef(0.25f, 0.0f, -5.0f);
            Print_Font("D");
            glPopMatrix();
        }

        if (Print_I)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(4.0f, 0.0f, 0.0f);
            Print_Font("I");
        }
        if (!Print_I && Stick_I)
        {
            glPushMatrix();
            glTranslatef(0.75f, 0.0f, -5.0f);
            Print_Font("I");
            glPopMatrix();
        }

        if (Print_C)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(4.5f, 0.0f, 0.0f);
            Print_Font("C");
        }
        if (!Print_C && Stick_C)
        {
            glPushMatrix();
            glTranslatef(1.25f, 0.0f, -5.0f);
            Print_Font("C");
            glPopMatrix();
            
        }

        if (Print_CO)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }

            glTranslatef(5.0f, 0.0f, 0.0f);
            Print_Font("O");
            if (X_for_present < -1.5f)
            {
                X_for_present += 0.01f;
            }
        }
        if (!Print_CO && Stick_CO)
        {
            glPushMatrix();
            glTranslatef(1.75f, 0.0f, -5.0f);
            Print_Font("O");
            glPopMatrix();

            if (X_for_present < -1.5f)
            {
                X_for_present += 0.01f;
            }
            
        }

        glPushMatrix();

        glTranslatef(X_for_present, -1.0f, -5.0f);
        Print_Font("Presents");

        glPopMatrix();

        if (Print_CM)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(5.5f, 0.0f, 0.0f);
            Print_Font("M");
        }
        if (!Print_CM && Stick_CM)
        {
            glPushMatrix();
            glTranslatef(2.25f, 0.0f, -5.0f);
            Print_Font("M");
            glPopMatrix();
            
        }

        if (Print_P)
        {
            if (incre > 0.0f)
            {
                glTranslatef(Font_X, Font_Y + incre, Font_Z);
            }
            else
            {
                glTranslatef(Font_X, sin_Fix_val * sinf(sin_y), Font_Z);
            }
            glTranslatef(6.25f, 0.0f, 0.0f);
            Print_Font("P");
        }
        if (!Print_P && Stick_P)
        {
            glPushMatrix();
            glTranslatef(3.0f, 0.0f, -5.0f);
            Print_Font("P");
            glPopMatrix();
            fade_in_christmas_Scene = true;
            bStart_Font = false;
            bStart_Animation = true;
            PlaySoundW(MAKEINTRESOURCE(MYNIGHT), GetModuleHandleA(NULL), SND_RESOURCE | SND_ASYNC);
        }

        Font_update();

        glPopMatrix();

        glPopMatrix();
    }

    if (bStart_Animation)
    {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        gluLookAt(Camera_Position_X, Camera_Position_Y, Camera_Position_Z, Camera_Eye_X, Camera_Eye_Y, Camera_Eye_Z, 0.0f, 1.0f, 0.0f);
        


#pragma region Error_Checking

  /* glLineWidth(5.0f);

    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex3f(10.0f, 0.0f, 0.0f);
    glVertex3f(-10.0f, 0.0f, 0.0f);

    glVertex3f(0.0f, 10.0f, 0.0f);
    glVertex3f(0.0f, -10.0f, 0.0f);

    glEnd();
    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);
    */

#pragma endregion Error_Checking

    // Here we are dealing with Land, Sky and Tree
#pragma region Part_1
        glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);

        glPushMatrix();

#pragma region Tree
        //This is commented bacouse of High Load On GPU ,
        //if you comment out it you will see Tree in front of the House.
        //Thank you.

        //Left side


        glPushMatrix();

        glEnable(GL_TEXTURE_2D);
        glTranslatef(-8.0f, 1.0f, 3.0f);
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        glBindTexture(GL_TEXTURE_2D, Tree_Texture);

        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

        //Function Call
        Tree();

        glPopMatrix();



        //Right side
        glPushMatrix();

        glEnable(GL_TEXTURE_2D);
        glTranslatef(10.0f, 1.0f, 4.0f);
        glRotatef(angle, 0.0f, 1.0f, 0.0f);
        glBindTexture(GL_TEXTURE_2D, Tree_Texture);

        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        //glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

        //Function Call
        Tree();

        glPopMatrix();


#pragma endregion Tree

#pragma region Sky

        glDisable(GL_FOG);
        glPushMatrix();

        Sky();

        glPopMatrix();

        if (print)
            glEnable(GL_FOG);
        else
            glDisable(GL_FOG);

#pragma endregion Sky

#pragma region Land

        glPushMatrix();

        Land();

        glPopMatrix();

#pragma endregion Land

        glPopMatrix();

#pragma endregion Part_1

        //House Bushes House_Tree
#pragma region Part_2

        glPushMatrix();

        glTranslatef(0.0f, 2.0f, -10.0f);

        //glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);

#pragma region House

        glPushMatrix();



        House();

        glPopMatrix();

#pragma endregion House

#pragma region Bushes
        //This is commented bacouse of High Load On GPU ,
        //if you comment out it you will see the Bushes in front of the House.
        //Thank you.


        //From House 1
        glPushMatrix();

        glTranslatef(5.0f, -2.8f, 7.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        Bushes();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(-5.0f, -2.8f, 7.0f);

        glScalef(1.0f, 1.0f, 1.0f);
        Bushes();

        glPopMatrix();

        //From House 2
        glPushMatrix();

        glTranslatef(5.0f, -2.8f, 11.0f);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        Bushes();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(-5.0f, -2.8f, 11.0f);
        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);
        Bushes();

        glPopMatrix();

        //From House 3
        glPushMatrix();

        glTranslatef(5.0f, -2.8f, 15.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        Bushes();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(-5.0f, -2.8f, 15.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);
        Bushes();

        glPopMatrix();

        //From House 4
        glPushMatrix();

        glTranslatef(6.0f, -2.8f, 19.0f);
        glRotatef(200.0f, 0.0f, 1.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        Bushes();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(-6.0f, -2.8f, 19.0f);
        glRotatef(200.0f, 0.0f, 1.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);
        Bushes();

        glPopMatrix();


#pragma endregion Bushes

#pragma region House_Tree
        //This is commented bacouse of High Load On Computer ,
        //if you comment out it you will see the trees around the House.

         //Thank you.

         //right side
        for (int j = 0; j < 10; j++)
        {

            glPushMatrix();

            glTranslatef((GLfloat)rand_val_2[j], -3.0f, ((GLfloat)rand_val[j]) + rand_val_3[j]);

            glTranslatef(17.0f, 0.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glScalef(4.0f, 4.0f, 4.0f);

            House_Tree();

            glPopMatrix();
        }

        glTranslatef(10.0f, 0.0f, 15.0f);
        //right side
        for (int j = 0; j < 10; j++)
        {

            glPushMatrix();

            glTranslatef((GLfloat)rand_val_2[j], -3.0f, ((GLfloat)rand_val[j]) + rand_val_3[j]);

            glTranslatef(17.0f, 0.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glScalef(4.0f, 4.0f, 4.0f);

            House_Tree();

            glPopMatrix();

        }

        glTranslatef(-15.0f, 0.0f, -5.0f);
        //Left side
        for (int j = 0; j < 10; j++)
        {

            glPushMatrix();

            glTranslatef((GLfloat)rand_val_2[j], -3.0f, ((GLfloat)rand_val[j]) + rand_val_3[j]);

            glTranslatef(-17.0f, 0.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glScalef(4.0f, 4.0f, 4.0f);

            House_Tree();

            glPopMatrix();
        }

        glTranslatef(-10.0f, 0.0f, 8.0f);
        //right side
        for (int j = 0; j < 10; j++)
        {

            glPushMatrix();

            glTranslatef((GLfloat)rand_val_2[j], -3.0f, ((GLfloat)rand_val[j]) + rand_val_3[j]);

            glTranslatef(-17.0f, 0.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glScalef(4.0f, 4.0f, 4.0f);

            House_Tree();

            glPopMatrix();
        }


        //glRotatef(180.0f, 0.0f, 1.0f, 0.0f);



#pragma endregion House_Tree

        glPopMatrix();

#pragma endregion Part_2

        //Girl
#pragma region Part_3

        glPushMatrix();

        glTranslatef(girl_Model_X, girl_Model_Y, girl_Model_Z);

        glRotatef(girl_Main_Body_angle, 0.0f, 1.0f, 0.0f);
        glScalef(2.5f, 2.5f, 2.5f);

        Girl();

        glPopMatrix();
#pragma endregion Part_3

        //Santa
#pragma region Part_4

#pragma region santa

        glPushMatrix();

        glTranslatef(santa_Model_X, santa_Model_Y, santa_Model_Z);

        glRotatef(Santa_Rotation, 0.0f, 1.0f, 0.0f);
        glScalef(2.5f, 2.5f, 2.5f);

        Santa();

        glPopMatrix();

#pragma endregion santa

#pragma region santa_Ferrari

        glPushMatrix();

        glTranslatef(Santa_Ferrari_Model_X, Santa_Ferrari_Model_Y, Santa_Ferrari_Model_Z);

        glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
        glScalef(1.5f, 1.5f, 1.5f);

        Santa_Ferrari();

        glPopMatrix();

#pragma endregion santa_Ferrari

#pragma endregion Part_4

        //Bird
#pragma region Part_5

        glPushMatrix();

        glTranslatef(-8.4f, 3.1f, 2.7f);

        Bird();

        glPopMatrix();

#pragma endregion Part_5

        //Snow
#pragma region Part_6

    //This is commented bacouse of High Load On GPU ,
    //if you comment out it you will see the Snow falling down around the House.
    //Thank you.
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_FOG);
        //glEnable(GL_LIGHTING);

        //Center of Geometric
        glPushMatrix();

        Snow();

        glPopMatrix();

        glPushMatrix();
        glTranslatef(10.0f, 5.0f, 0.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-10.0f, -5.0f, 0.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0f, 10.0f, 10.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(30.0f, 0.0f, 0.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-30.0f, 0.0f, 0.0f);
        Snow();
        glPopMatrix();

        //front Section 
        glPushMatrix();
        glTranslatef(10.0f, 5.0f, 15.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-10.0f, -5.0f, 15.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 15.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(30.0f, 0.0f, 15.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-30.0f, 0.0f, 15.0f);
        Snow();
        glPopMatrix();

        //Back Section
        glPushMatrix();
        glTranslatef(10.0f, 5.0f, -15.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-10.0f, -5.0f, -15.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -15.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(30.0f, 0.0f, -15.0f);
        Snow();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-30.0f, 0.0f, -15.0f);
        Snow();
        glPopMatrix();

        glDisable(GL_LIGHTING);
#pragma endregion Part_6

        //Mountains
#pragma region Part_7


        glPushMatrix();

        glTranslatef(-10.0f, -1.0f, -40.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(10.0f, -1.0f, -30.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(40.0f, -1.0f, -30.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(-30.0f, -1.0f, -30.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();
        glPushMatrix();

        glTranslatef(30.0f, -1.0f, -30.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();

        glPushMatrix();

        glTranslatef(-40.0f, -1.0f, 20.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();
        glPushMatrix();

        glTranslatef(40.0f, -1.0f, 20.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();
        glPushMatrix();

        glTranslatef(-10.0f, -1.0f, -40.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();


        glPopMatrix();
        glPushMatrix();

        glTranslatef(-25.0f, -1.0f, 45.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();
        glPopMatrix();
        glPushMatrix();

        glTranslatef(-45.0f, -1.0f, 45.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();
        glPopMatrix();
        glPushMatrix();

        glTranslatef(40.0f, -1.0f, 45.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(0.0f, -1.0f, 45.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(25.0f, -1.0f, 45.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();
        glPopMatrix();

        glPushMatrix();

        glTranslatef(45.0f, -1.0f, -5.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();
        glPushMatrix();

        glTranslatef(-45.0f, -1.0f, -10.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();
        glPushMatrix();

        glTranslatef(-45.0f, -1.0f, -40.0f);
        glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

        Mountain();

        glPopMatrix();
        if (print)
            glEnable(GL_FOG);
        else
            glDisable(GL_FOG);
#pragma endregion Part_7

        //Gift
#pragma region Part_8

        glPushMatrix();

        glTranslatef(Gift_Model_X, Gift_Model_Y, Gift_Model_Z);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glRotatef(angle_gift, 0.0f, 0.0f, 1.0f);

        Gift();

        glPopMatrix();

#pragma endregion Part_8

#pragma region Tree

        //Right side
        glPushMatrix();
        glTranslatef(15.0f, 2.0f, 10.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

        for (int j = 0; j < 10; j++)
        {

            glPushMatrix();

            glTranslatef((GLfloat)rand_val_2[j], -3.0f, ((GLfloat)rand_val[j]) + rand_val_3[j]);

            glTranslatef(-17.0f, 0.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glScalef(4.0f, 4.0f, 4.0f);

            House_Tree();

            glPopMatrix();
        }
        glPopMatrix();

        //Middle side
        glPushMatrix();
        glTranslatef(-2.5f, 2.0f, 12.5f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

        for (int j = 0; j < 10; j++)
        {

            glPushMatrix();

            glTranslatef((GLfloat)rand_val_2[j], -3.0f, ((GLfloat)rand_val[j]) + rand_val_3[j]);

            glTranslatef(-17.0f, 0.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glScalef(4.0f, 4.0f, 4.0f);

            House_Tree();

            glPopMatrix();
        }
        glPopMatrix();

        //Left side
        glPushMatrix();
        glTranslatef(-14.5f, 2.0f, 8.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

        for (int j = 0; j < 10; j++)
        {

            glPushMatrix();

            glTranslatef((GLfloat)rand_val_2[j], -3.0f, ((GLfloat)rand_val[j]) + rand_val_3[j]);

            glTranslatef(-17.0f, 0.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glScalef(4.0f, 4.0f, 4.0f);

            House_Tree();

            glPopMatrix();
        }
        glPopMatrix();

#pragma endregion Tree

#pragma region Girl_Animation 

        if (girl_Restor_Position)
        {
            Restore_update_girl();
        }

        if (girl_Rotating_Position)
        {
            Rotating_update_girl();
        }

        if (girl_Walking)
        {
            girl_Restor_Position = false;
            Walking_update_girl();
        }

        if (girl_Door_Opening)
        {

            if (girl_Animation)
            {
                Door_Opening_girl_Animation();
            }

            if (Door_Motion)
            {
                if (girl_sholder_Left < 180)
                {
                    girl_sholder_Left += 1.0f;
                }

                Door_Opening();
            }

            if (Close_Door)
            {
                if (Door_angle > 0)
                {
                    Door_angle -= 0.6f;

                }
                else
                {
                    part_3 = true;
                    girl_Door_Opening = false;
                    play_Christmas_Sound = true;

                }
            }
        }


#pragma endregion Girl_Animation 


#pragma region Sound_Playing
        
        if (play_Christmas_Sound)
        {
            PlaySoundW(MAKEINTRESOURCE(MYSANTA_TRACK), GetModuleHandleA(NULL), SND_RESOURCE | SND_ASYNC);
            play_Christmas_Sound = false;
        }
#pragma endregion Sound_Playing


#pragma region Santa_Animation

        if (santa_walk)
            Walking_Santa();

        if (santa_Restore)
        {
            if (santa_Model_Y > 0.55f || santa_Model_Z > 13.0f || Santa_Rotation > 0.0f)
                Restore_Santa();
        }

        if (Move_Santa_and_Ferrari)
        {
            if (Santa_Ferrari_Model_X > -1.0f)
            {
                Transform_Santa_Ferrari();
            }
            if (Santa_Ferrari_Model_X < 0.0f && santa_Model_Z > 14.0f)
            {
                santa_Restore = true;
            }
        }

        if (Santa_Bring_Gift)
        {
            Santa_Bringing_Gift();
        }

#pragma endregion Santa_Animation

#pragma region Camera_Position

        if (Camera_Move)
        {
            Camera_update();
        }


#pragma endregion Camera_Position

#pragma region Fade_It

        Fade_In_Out();

#pragma endregion Fade_It

    }
    
    if (bStart_End)
    {
        glPushMatrix();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glColor3f(f_fade_in_x, f_fade_in_y, f_fade_in_z);

        glPushMatrix();

        glEnable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        glBindTexture(GL_TEXTURE_2D, Sky_Texture);
        glBegin(GL_QUADS);

        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(5.0f, 4.0f, -6.0f);

        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-5.0f, 4.0f, -6.0f);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-5.0f, -4.0f, -6.0f);

        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(5.0f, -4.0f, -6.0f);

        glEnd();
        glDisable(GL_TEXTURE_2D);

        glPopMatrix();

        glPushMatrix();

        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        
        if (incre_End_Thanks < -2.0f)
        {
            glTranslatef(incre_End_Thanks, 0.0f, -5.0f);
            incre_End_Thanks += 0.005f;
        }
        else
        {
            glTranslatef(-2.0f, 0.0f, -5.0f);
        }

        Print_Font("Thank you !");
     
        glPopMatrix();

        glPopMatrix();
    }

    SwapBuffers(ghdc_DM);
}

void Fade_In_Out(void)
{
    if (fade_in_christmas_Scene)
    {
        if (gl_fade_x < 1.0f)
        {
            gl_fade_x += 0.005f;
            gl_fade_y += 0.005f;
            gl_fade_z += 0.005f;
            print = true;
            if (gl_fade_x < 0.5f)
            {
                start_snow_fall = true;
                Camera_Move = true;
            }
        }
        else
        {
            fade_in_christmas_Scene = false;
        }
    }
    
    if (fade_out_christmas_Scene)
    {
        if (gl_fade_x > 0.0f)
        {
            gl_fade_x -= 0.005f;
            gl_fade_y -= 0.005f;
            gl_fade_z -= 0.005f;
            
            //Removing the Lights from models

            if(gl_fade_x < 0.5f)
                print = false;
        }
        else
        {
            fade_out_christmas_Scene = false;
            bStart_End = true;
            bStart_Animation = false;
        }
    }
}

void Font_update(void)
{

    if (Print_)
    {
        if (incre > 0.0f)
        {
            incre -= 0.03f;
        }
        else
        {
            Animate = true;
        }
        if (Animate)
        {
            if (sin_y > -30.0f)
            {
                sin_y -= 0.04f;
                if (sin_Fix_val > 0.0f)
                {
                    sin_Fix_val -= 0.0006f;
                }
                else
                {
                    Print_ = false;
                }
            }
        }
    }
    else
    {
        char_count++;
        incre = 3.0f;
        sin_y = 10.0f;
        Animate = false;
        sin_Fix_val = 0.2f;
        Print_ = true;

        if (char_count == 1)
        {
            Print_A = false;
            Print_S = true;
        }
        if (char_count == 2)
        {
            Print_S = false;
            Print_T = true;
            Stick_S = true;
        }
        if (char_count == 3)
        {
            Print_T = false;
            Print_R = true;
            Stick_T = true;
        }
        if (char_count == 4)
        {
            Print_R = false;
            Print_O = true;
            Stick_R = true;
        }
        if (char_count == 5)
        {
            Print_O = false;
            Print_M = true;
            Stick_O = true;
        }
        if (char_count == 6)
        {
            Print_M = false;
            Print_E = true;
            Stick_M = true;
        }
        if (char_count == 7)
        {
            Print_E = false;
            Print_D = true;
            Stick_E = true;
        }
        if (char_count == 8)
        {
            Print_D = false;
            Print_I = true;
            Stick_D = true;
        }
        if (char_count == 9)
        {
            Print_I = false;
            Print_C = true;
            Stick_I = true;
        }
        if (char_count == 10)
        {
            Print_C = false;
            Print_CO = true;
            Stick_C = true;
        }
        if (char_count == 11)
        {
            Print_CO = false;
            Print_CM = true;
            Stick_CO = true;
        }
        if (char_count == 12)
        {
            Print_CM = false;
            Print_P = true;
            Stick_CM = true;
        }
        if (char_count == 13)
        {
            Print_P = false;
            Stick_P = true;
        }
    }
    
}

GLvoid Print_Font(const char* fmt, ...)     // Custom GL "Print" Routine
{
    char* text;                          // Holds Our String

    if (fmt == NULL)                         // If There's No Text
        return;

    // Do Nothing
    text = (char*)fmt;

    glPushAttrib(GL_LIST_BIT);                          // Pushes The Display List Bits
    glListBase(base);                                   // Sets The Base Character to 0
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);  // Draws The Display List Text
    glPopAttrib();                                      // Pops The Display List Bits
}

void Camera_update(void)
{
   
    if (part_1)
    {
        if ((Camera_Eye_Y < 0.0f) || (Camera_Position_X < 50.0f))
        {
            if (Camera_Position_X < -30.0f)
            {
                Camera_Eye_Y += 0.1f;

            }
            else if (Camera_Position_X < -20.0f)
            {
                Camera_Eye_Y += 0.2f;

            }

            if (Camera_Position_X < -5.0f && Camera_Position_X > -30.0f)
            {
                Camera_Position_X += 0.1f;
                
            }
            else
            {
                Camera_Position_X += 0.1f;
            }
            if (Camera_Position_Z > 11.0f)
            {
                Camera_Position_Z -= 0.1f;

            }
            if (Camera_Position_Y > 2.0f)
            {
                Camera_Position_Y_Increment += 0.001f;
                Camera_Position_Y -= Camera_Position_Y_Increment;
            }
            if (Camera_Position_X > 12.0f)
            {

                part_1 = false;
                part_2 = true;

            }

        }

    }

    if (part_2)
    {
        girl_Restor_Position = true;

        if (Camera_Eye_X > 20.0f || Camera_Position_Z > 3.0f)
        {
            if (Camera_Eye_X > 2.5f)
            {
                Camera_Eye_X -= 0.5f;
                if (Camera_Position_Y < 10.0f)
                {
                    Camera_Position_Y += 0.006f;
                    Camera_Eye_Y += 0.02f;
                }
            }
            else if (Camera_Position_Z > 3.0f)
            {
                Camera_Position_Z -= 0.05f;
            } 

        }
        else
        {
            part_2 = false;

        }
    }

    if (part_3)
    {

        if (Camera_Position_Z > -20.0f)
        {
            Camera_Position_Z -= 0.05f;
            if (Camera_Position_Z < -10.0f)
            {
                             
                Black_Front_right = true;
                Black_Right = true;
                
            }

        }
        else
        {
            if (Camera_Position_X > -15.0f)
            {
                Camera_Position_X -= 0.05f;
                if (Camera_Position_X < 10.0f)
                {
                    Black_Back_Right = true;
                }
                if (Camera_Position_X < -10.0f)
                {
                    Black_Back_Left = true;
                }
            }
            else
            {
                part_4 = true;
                part_3 = false;
            }
        }
        
    }

    if (part_4)
    {
       
        if (Camera_Position_Z < 15.0f)
        {
             Move_Santa_and_Ferrari = true;
            Camera_Position_Z += 0.08f;

            if (Camera_Position_Z > -10.0f)
            {
                
                Black_Left = true;
                Black_Front_Left = true;

            }
               
            //Activate the walking santa mode
            if (Camera_Position_Z > 12.0f && santa_Model_X < -0.5f)
            {
                
            }

        }
        else
        {
            
            part_5 = true;
            part_4 = false;
        }
    }

    if (part_5)
    {
        if (santa_Model_Z < -2.0f)
        {
            Black_Front_Left = false;
            Black_Left = false;
            Black_Back_Left = false;
        }
        //else
        //{
        //    //part_5 = false;
        //    fprintf_s(gpFile_DM, "\n\n**************************************************\n\n");
        //    fprintf_s(gpFile_DM, "Camera Eye X = %f\n", Camera_Eye_X);
        //    fprintf_s(gpFile_DM, "Camera Eye Y = %f\n", Camera_Eye_Y);
        //    fprintf_s(gpFile_DM, "Camera Eye Z = %f\n", Camera_Eye_Z);
        //    fprintf_s(gpFile_DM, "Camera Position X = %f\n", Camera_Position_X);
        //    fprintf_s(gpFile_DM, "Camera Position Y = %f\n", Camera_Position_Y);
        //    fprintf_s(gpFile_DM, "Camera Position Z = %f\n", Camera_Position_Z);
        //}
        if (santa_Model_Z > 0.0f && !Black_Back_Left)
        {
            Black_Front_right = false;
            Black_Right = false;
            Black_Back_Right = false;
        }
        
        if (Camera_Position_X < 10.0f)
        {
            Camera_Position_X += 0.05f;
            Camera_Eye_X -= 0.006f;
            if (Camera_Position_X < 0.0f)
            {
                santa_walk = true;
                
            }
            if (Camera_Position_X < 1.0f)
            {
                Santa_Front_Walking = true;
            }
        }
        
        if (Camera_Position_X > 9.0f && santa_Model_Z > 9.8f && Black_Front_right == false)
        {
            part_6 = true;
            part_5 = false;
            fprintf_s(gpFile_DM, "\n\ncondition is succeded...!!!!\n\n");
            
        }

    }

    if (part_6)
    {
        if (Camera_Position_X > 0.0f)
        {
            Camera_Position_X -= 0.04f;
            Camera_Position_Z += 0.038f;
            Camera_Eye_X += 0.012f;
            if (Santa_Ferrari_Model_X > -10.0f)
            {
                Santa_Ferrari_Model_X -= 0.05f;
            }
        }
        else
        {
            part_6 = false;
            
        }

    }
}

void Santa_Bringing_Gift(void)
{
    if (Gift_Model_Z < -1.9f && Gift_Model_Z > -3.0f)
    {
        santa_walk = false;
        Gift_Model_Z -= 0.005f;
        santa_Restore = false;
    }
    else {
        
        if (Santa_Rotation < 180.0f)
        {
            Santa_Rotation += 1.0f;
            if (santa_Lbow_Right < 355.0f)
            {
                santa_Lbow_Right += 1.0f;
                santa_Lbow_Left += 1.0f;
            }
            santa_walk = true;
        }
        else
        {
            if (santa_Model_Z < 10.0f)
            {
                santa_Model_Z += 0.05f;
            }
            else
            {
                santa_walk = false;
            }
        }
    }
}

void Gift(void)
{
    //glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    //glDisable(GL_LIGHTING);

    glBindTexture(GL_TEXTURE_2D, Gift_Texture);
    

    glBegin(GL_QUADS);

    //Front

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 0.3f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 0.3f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -0.3f, 0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -0.3f, 0.5f);
    
    //Back
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 0.3f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 0.3f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -0.3f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -0.3f, -0.5f);

    //Left
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, 0.3f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 0.3f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -0.3f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -0.3f, 0.5f);

    //Right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 0.3f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 0.3f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, -0.3f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -0.3f, 0.5f);

    //Top
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.1f, 0.5f, 0.6f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.1f, 0.5f, -0.6f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.1f, 0.5f, -0.6f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.1f, 0.5f, 0.6f);

    //Bottom
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -0.3f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, -0.3f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, -0.3f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -0.3f, 0.5f);

    //Top Front 
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.1f, 0.5f, 0.6f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.1f, 0.5f, 0.6f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.1f, 0.3f, 0.6f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.1f, 0.3f, 0.6f);
    
    //Top back 
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.1f, 0.5f, -0.6f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.1f, 0.5f, -0.6f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.1f, 0.3f, -0.6f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.1f, 0.3f, -0.6f);

    //Top left
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.1f, 0.5f, 0.6f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.1f, 0.5f, -0.6f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.1f, 0.3f, -0.6f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.1f, 0.3f, 0.6f);

    //Top Right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.1f, 0.5f, 0.6f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.1f, 0.5f, -0.6f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.1f, 0.3f, -0.6f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.1f, 0.3f, 0.6f);

    glEnd();

    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);

    glDisable(GL_LIGHTING);



    /*glPushMatrix();

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.5f, 0.5f, 1.0f, 30, 30);

    glPopMatrix();

    glDisable(GL_LIGHTING);
    
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(1.0f, 0.05f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);*/


}

void Transform_Santa_Ferrari(void)
{
    static  GLfloat decrement = 0.15f;


    if (decrement > 0.0f)
    {
        santa_Model_X -= decrement;
        Santa_Ferrari_Model_X -= decrement;
        Gift_Model_X -= decrement;
    }
    else
    {
        santa_Model_X += decrement;
        Santa_Ferrari_Model_X += decrement;
        Gift_Model_X += decrement;

    }
    decrement -= 0.0005f;
}

void Restore_Santa(void)
{
    if (santa_Restore)
    {
        if(santa_Model_Y > 0.55f)
            santa_Model_Y -= 0.01f;

        if(santa_Model_Z > 13.0f)
            santa_Model_Z -= 0.05f;

        if(Santa_Rotation > 0.0f)
            Santa_Rotation -= 1.3f;

        if (santa_Lbow_Right > 170.0f)
        {
            santa_Lbow_Right -= 1.0f;
            santa_Lbow_Left -= 1.0f;
        }
        if (Gift_Model_Z > 12.25f)
        {
            Gift_Model_Z -= 0.05f;
        }

        if (Gift_Model_Y > 0.3f)
        {
            Gift_Model_Y -= 0.05f;
        }
        
        if (angle_gift > 270)
        {
            angle_gift -= 1.2f;
        }

        if (Gift_Model_X > -1.0f)
        {
            Gift_Model_X -= 0.05f;
        }


    }
}

void Mountain(void)
{
    //glEnable(GL_TEXTURE_2D);

    glColor3f(0.3f * gl_fade_x, 0.7f * gl_fade_y, 1.0f * gl_fade_z);
    quadric = gluNewQuadric();
    gluCylinder(quadric, 10.0f, 0.0f, 10.0f, 20, 20);

    glDisable(GL_TEXTURE_2D);
    glTranslatef(0.0f, 0.0f, 5.0f);
    
    glColor3f(0.8f * gl_fade_x, 0.8f * gl_fade_y, 0.8f * gl_fade_z);

    quadric = gluNewQuadric();
    gluCylinder(quadric, 5.0f, 0.0f, 7.0f, 20, 20);

    glEnable(GL_TEXTURE_2D);

}

void Walking_Santa(void)
{
    //Walking body 

    if (move_Front_Right_s)
    {
        if (santa_Thigh_Right < 200)
        {
            santa_Thigh_Right += 0.7f;
            santa_Calf_Right -= 0.7f;
        }

        if (santa_Thigh_Right > 197)
        {
            move_Front_Right_s = false;
            move_Back_Right_s = true;
        }
    }

    if (move_Back_Right_s)
    {
        if (santa_Thigh_Right > 155)
        {
            santa_Thigh_Right -= 0.7f;
            santa_Calf_Right += 0.7f;
        }

        if (santa_Thigh_Right < 160)
        {
            move_Front_Right_s = true;
            move_Back_Right_s = false;
        }
    }

    if (move_Front_Left_s)
    {
        if (santa_Thigh_Left < 200)
        {
            santa_Thigh_Left += 0.7f;
            santa_Calf_Left -= 0.7f;
        }

        if (santa_Thigh_Left > 197)
        {
            move_Front_Left_s = false;
            move_Back_Left_s = true;
        }
    }

    if (move_Back_Left_s)
    {
        if (santa_Thigh_Left > 155)
        {
            santa_Thigh_Left -= 0.7f;
            santa_Calf_Left += 0.7f;
        }

        if (santa_Thigh_Left < 160)
        {
            move_Front_Left_s = true;
            move_Back_Left_s = false;
        }
    }

    if (Santa_Front_Walking)
    {
        if (santa_Model_Z > -2.0f)
        {
            if(!Santa_Bring_Gift)
                santa_Model_Z -= 0.007f;
            
            if(Gift_Model_Z > -5.0f)
                Gift_Model_Z -= 0.007f;
        }
        else
        {
            Santa_Bring_Gift = true;
        }
    }

}

void Door_Opening( void )
{
    if (Door_angle < 45)
    {
        Door_angle += 0.6f;

    }
    else
    {
        girl_Walking = true;
        girl_Rotating_Position = true;
        Door_Motion = false;
        
    }
}

void Door_Opening_girl_Animation(void)
{
    if (girl_sholder_Left > 75.0f)
        girl_sholder_Left -= 1.0f;
    else
    {
        Door_Motion = true;
        girl_Animation = false;
        move_Front_Right = true;
        move_Front_Left = false;
        
    }
}

void Walking_update_girl(void)
{
    //Walking body 
 
    if (move_Front_Right)
    {
        if (girl_Thigh_Right < 200)
        {
            girl_Thigh_Right += 0.6f;
            girl_Calf_Right -= 0.6f;
        }

        if (girl_Thigh_Right > 197)
        {
            move_Front_Right = false;
            move_Back_Right = true;
        }
    }

    if (move_Back_Right)
    {
        if (girl_Thigh_Right > 155)
        {
            girl_Thigh_Right -= 0.6f;
            girl_Calf_Right += 0.6f;
        }

        if (girl_Thigh_Right < 157)
        {
            move_Back_Right = false;
            move_Front_Right = true;
        }
    }

    if (move_Front_Left)
    {
        if (girl_Thigh_Left < 200)
        {
            girl_Thigh_Left += 0.6f;
            girl_Calf_Left -= 0.6f;
        }

        if (girl_Thigh_Left > 197)
        {
            move_Front_Left = false;
            move_Back_Left = true;
        }
    }

    if (move_Back_Left)
    {
        if (girl_Thigh_Left > 155)
        {
            girl_Thigh_Left -= 0.6f;
            girl_Calf_Left += 0.6f;
        }

        if (girl_Thigh_Left < 157)
        {
            move_Front_Left = true;
            move_Back_Left = false;
        }
    }

}

void Rotating_update_girl(void)
{
    static bool girl_Move = false;

    static bool girl_Move_incremente = true;
    static GLfloat increment_X = 0.0f;
    static GLfloat increment_Y = 0.0f;
    
    if (girl_Main_Body_angle < 360)
    {
        
        girl_Main_Body_angle += 1;
        

        if (girl_Main_Body_angle > 355)
        {
            girl_Move = true;

        }
    }
    
    if(girl_Move)
    {
        if (girl_Model_Z > -7.0f)
        {

            girl_Model_Z -= increment_Y;
            girl_Model_X += increment_X;
        }
        else if (girl_Model_Z > -10.0f && girl_Model_Z < -7.0f && Door_angle > 40)
        {
            increment_X -= 0.00003f;
            increment_Y += 0.000745f;
            girl_Model_Z -= increment_Y;
            girl_Model_X += increment_X;
            girl_Walking = true;
            girl_Move_incremente = false;
            
        }
        else
        {
            girl_Walking = false;
        }
        if (girl_Model_Z < -9.5f)
        {
            Close_Door = true;
        }
    }

    if(girl_Move_incremente)
    {
        increment_X += 0.000018f;
        increment_Y += 0.00002f;

    }
}

void Restore_update_girl(void)
{
    //Left hand
    if (girl_sholder_Left <= 180)
    {
        girl_sholder_Left += 1;
        
    }
    if (girl_Lbow_Left <= 355)
    {
        girl_Lbow_Left += 1;
    }
    if (girl_Lbow_Bending > 0)
    {
        girl_Lbow_Bending -= 1;

    }

    //Right hand 
    if (girl_sholder_Right <= 180)
    {
        girl_sholder_Right += 1;

    }
    if (girl_Lbow_Right <= 355)
    {
        girl_Lbow_Right += 1;
    }

    //Right Leg
    if (girl_Thigh_Right <= 180)
    {
        girl_Thigh_Right += 1;
    }

    if (girl_Calf_Right >= 5)
    {
        girl_Calf_Right -= 1;
    }

    //Left Leg
    if (girl_Thigh_Left <= 180)
    {
        girl_Thigh_Left += 1;
    }

    if (girl_Calf_Left >= 5)
    {
        girl_Calf_Left -= 1;
    }

    if (girl_Model_Y <= 1.6f)
    {
        girl_Model_Y += 0.008f;
    }

    if (girl_Thigh_Left > 180.0f && girl_sholder_Left >180.0f)
    {
        girl_Rotating_Position = true;
       
        girl_Restor_Position = false;
        
    }
   
}

void Snow(void)
{
    //LocalVariables for Snow
    struct Snow* Temp = NULL, * Temp_Local = NULL, * Temp_2 = NULL, * Temp_3 = NULL, * Temp_4 = NULL, * Temp_5 = NULL;
    Temp = Front;
    Temp_2 = Front_2;
    Temp_3 = Front_3;
    Temp_4 = Front_4;
    Temp_5 = Front_3;

    int i = 0;
    int j = 0;

    //Local Function for Updating the Y value
    void update(bool, bool, bool, bool);

    while (Temp->Next != NULL, i < 4)
    {
        Temp_Local = Front;
        j = 0;
        while (Temp_Local->Next != NULL, j < 10)
        {
            
            glPushMatrix();

            if(j < 5)
                glTranslatef(4.0f * sinf((GLfloat)(rand_val[j] / 10.0f)), 2.0f + sinf((GLfloat)(rand_val[j] / 10.0f)), 0.0f);
            else
               glTranslatef(-8.0f * sinf((GLfloat)(rand_val[i] / 10.0f)), 0.0f, 0.0f);

            glEnable(GL_POINT_SMOOTH);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
            glPointSize(10.0f);
            glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);
            glBegin(GL_POINTS);

            if (i < 2)
                glVertex3f(-Temp_Local->x  + (sinf((GLfloat)(rand_val[i] / 10.0f))), snow_fall_1 - Temp_Local->y , -Temp_Local->z);
            else if (i < 3 && i > 1)
                glVertex3f(Temp_Local->x , snow_fall_1 - Temp_Local->y - (sinf((GLfloat)(rand_val[i] / 10.0f))), -Temp_Local->z);
            else
                glVertex3f(Temp_Local->x, snow_fall_1 - Temp_Local->y, Temp_Local->z - (sinf((GLfloat)(rand_val[i] / 10.0f))));
            
            glEnd();

            glPopMatrix();
            
           
            Temp_Local = Temp_Local->Next;
            j++;
        }
        glTranslatef(0.015f * sinf((GLfloat)(rand_val_3[i])), 0.05f * cosf((GLfloat)(rand_val[i])), 0.06f * cosf((GLfloat)(rand_val[i])));
        Temp = Temp->Next;
        i++;

    }

    
    if (snow_fall_1 < 10.0f)
    {
        snow_flag_2 = true;
    }

    //Front 2
    i = 0;
    while (Temp_2->Next != NULL, i < 4)
    {
        Temp_Local = Front_2;
        j = 0;
        while (Temp_Local->Next != NULL, j < 10) 
        {
            glPushMatrix(); 

            if (j < 5)
                glTranslatef(4.0f * sinf((GLfloat)(rand_val[j] / 10.0f)), 2.0f + sinf((GLfloat)(rand_val[j] / 10.0f)), 0.0f);
            else
                glTranslatef(-8.0f * sinf((GLfloat)(rand_val[i] / 10.0f)), 0.0f, 0.0f);

            glEnable(GL_POINT_SMOOTH);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
            glPointSize(10.0f);
            glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);
            glBegin(GL_POINTS);

            if (i < 2)
                glVertex3f(-Temp_Local->x + (sinf((GLfloat)(rand_val[i] / 10.0f))), snow_fall_2 - Temp_Local->y, -Temp_Local->z);
            else if (i < 3 && i > 1)
                glVertex3f(Temp_Local->x, snow_fall_2 - Temp_Local->y - (sinf((GLfloat)(rand_val[i] / 10.0f))), -Temp_Local->z);
            else
                glVertex3f(Temp_Local->x, snow_fall_2 - Temp_Local->y, Temp_Local->z - (sinf((GLfloat)(rand_val[i] / 10.0f))));

            glEnd();

            glPopMatrix();

            Temp_Local = Temp_Local->Next;
            j++;
        }
        Temp_2 = Temp_2->Next;
        i++;
        glTranslatef(0.1f * sinf((GLfloat)(rand_val[i] / 10.0f)), 0.2f * cosf((GLfloat)(rand_val[i] / 10.0f)), 0.06f * cosf((GLfloat)(rand_val[i] / 10.0f)));
    }
    
    if (snow_fall_2 < 10.0f)
    {
        snow_flag_3 = true;
    }
    
    //Front 3
    i = 0;
    
    while (Temp_3->Next != NULL, i < 4)
    {

        Temp_Local = Front_3;
        j = 0;
        while (Temp_Local->Next != NULL, j < 10)
        {
            glPushMatrix();

            if (j < 5)
                glTranslatef(4.0f * sinf((GLfloat)(rand_val[j] / 10.0f)), 2.0f + sinf((GLfloat)(rand_val[j] / 10.0f)), 0.0f);
            else
                glTranslatef(-8.0f * sinf((GLfloat)(rand_val[i] / 10.0f)), 0.0f, 0.0f);

            glEnable(GL_POINT_SMOOTH);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
            glPointSize(10.0f);
            glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);
            glBegin(GL_POINTS);

            if (i < 2)
                glVertex3f(-Temp_Local->x + (sinf((GLfloat)(rand_val[i] / 10.0f))), snow_fall_3 - Temp_Local->y, -Temp_Local->z);
            else if (i < 3 && i > 1)
                glVertex3f(Temp_Local->x, snow_fall_3 - Temp_Local->y - (sinf((GLfloat)(rand_val[i] / 10.0f))), -Temp_Local->z);
            else
                glVertex3f(Temp_Local->x, snow_fall_3 - Temp_Local->y, Temp_Local->z - (sinf((GLfloat)(rand_val[i] / 10.0f))));

            glEnd();

            glPopMatrix();

            Temp_Local = Temp_Local->Next;
            j++;
        }
        Temp_3 = Temp_3->Next;
        i++;
        glTranslatef(0.0f, 0.2f * cosf((GLfloat)(rand_val[i] / 10.0f)), 0.06f * cosf((GLfloat)(rand_val[i] / 10.0f)));
    }
    
    if (snow_fall_3 < 10.0f)
    {
        snow_flag_4 = true;
    }

    
    //Front 4
    i = 0;
    
    while (Temp_4->Next != NULL, i < 4)
    {
        Temp_Local = Front_4;
        while (Temp_Local->Next != NULL)
        {
            glPushMatrix();

            if (j < 5)
                glTranslatef(4.0f * sinf((GLfloat)(rand_val[j] / 10.0f)), 2.0f + sinf((GLfloat)(rand_val[j] / 10.0f)), 0.0f);
            else
                glTranslatef(-8.0f * sinf((GLfloat)(rand_val[i] / 10.0f)), 0.0f, 0.0f);

            glEnable(GL_POINT_SMOOTH);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
            glPointSize(10.0f);
            glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);
            glBegin(GL_POINTS);

            if (i < 2)
                glVertex3f(-Temp_Local->x + (sinf((GLfloat)(rand_val[i] / 10.0f))), snow_fall_4 - Temp_Local->y, -Temp_Local->z);
            else if (i < 3 && i > 1)
                glVertex3f(Temp_Local->x, snow_fall_4 - Temp_Local->y - (sinf((GLfloat)(rand_val[i] / 10.0f))), -Temp_Local->z);
            else
                glVertex3f(Temp_Local->x, snow_fall_4 - Temp_Local->y, Temp_Local->z - (sinf((GLfloat)(rand_val[i] / 10.0f))));

            glEnd();

            glPopMatrix();
            Temp_Local = Temp_Local->Next;

        }
        Temp_4 = Temp_4->Next;
        i++;
        glTranslatef(0.0f, 0.15f * cosf((GLfloat)(rand_val_2[i] / 10.0f)), 0.06f * cosf((GLfloat)(rand_val_2[i] / 10.0f)));
    }
   

    if (start_snow_fall)
    {
        update(snow_flag_1, snow_flag_2, snow_flag_3, snow_flag_4);
    }

}

void update(bool flag_1, bool flag_2, bool flag_3, bool flag_4)
{
    if (flag_1)
    {
        snow_fall_1 -= 0.008f;
        if (snow_fall_1 < -15.0f)
        {
            snow_fall_1 = 20.0f;
        }
    }

    if (flag_2)
    {
        snow_fall_2 -= 0.008f;
        if (snow_fall_2 < -15.0f)
        {
            snow_fall_2 = 20.0f;
        }
    }
    if (flag_3)
    {
        snow_fall_3 -= 0.008f;
        if (snow_fall_3 < -15.0f)
        {
            snow_fall_3 = 20.0f;
        }
    }
    if (flag_4)
    {
        snow_fall_4 -= 0.008f;
        if (snow_fall_4 < -15.0f)
        {
            snow_fall_4 = 20.0f;
        }
    }
}

void Bird(void)
{

#pragma region Start

    static GLfloat D = 0;
    //Body Begans
    //glTranslatef(0.0f, (GLfloat)0.05f * sinf(D), -3.0f);
    //glRotatef(angle, 0.0f, 1.0f, 0.0f);
     //glColor3f(0.7f, 1.0f, 1.0f);
     //glRotatef(10, 0.0f, 0.0f, 1.0f);

    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);
    //Bird head
#pragma region Bird_Head

    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Bird_Texture);

    glTranslatef(0.7f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 30, 30);

    glPushMatrix();

    //Eyes Texture

    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Bird_Bill_Texture);

    glTranslatef(0.0f, 0.0f, 0.1f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 30, 30);

    glTranslatef(0.0f, 0.0f, -0.2f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 30, 30);


    glPopMatrix();


    //Bill
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Bird_Bill_Texture);

    glTranslatef(0.08f, -0.02f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(10.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.03f, 0.0f, 0.1f, 10, 10);

    glPopMatrix();

    glPopMatrix();
#pragma endregion Bird_Head

    //Middle Body
#pragma region Middle_Body_Part
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Bird_Texture);
    glTranslatef(0.4f, 0.0f, 0.0f);
    glScalef(0.8f, 0.5f, 0.5f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.3f, 30, 30);

    glPopMatrix();
#pragma endregion Middle_Body_Part

    //Tail - (Puch(Sheput))
#pragma region BirdTail

    glPushMatrix();
    glRotatef(10.0f, 0.0f, 0.0f, 1.0f);

    glPushMatrix();

    glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.1f);
    glScalef(2.0f, 0.2f, 0.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1, 10, 10);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.05f);
    glScalef(2.0f, 0.2f, 0.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1, 10, 10);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(2.0f, 0.2f, 0.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1, 10, 10);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, -0.05f);
    glScalef(2.0f, 0.2f, 0.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1, 10, 10);

    glPopMatrix();

    glPushMatrix();

    glRotatef(350.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -0.1f);
    glScalef(2.0f, 0.2f, 0.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1, 10, 10);

    glPopMatrix();

    glPopMatrix();
#pragma endregion BirdTail

    //Bird Leg
#pragma region Bird_Legs

    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Bird_Bill_Texture);

    glTranslatef(0.4f, -0.1f, 0.05f);

    

    glRotatef(90, 1.0f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.01f, 0.01f, 0.2f, 10, 10);


    glPopMatrix();


    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Bird_Bill_Texture);

    glTranslatef(0.4f, -0.1f, -0.05f);

    glRotatef(90, 1.0f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.01f, 0.01f, 0.2f, 10, 10);

    glPopMatrix();
#pragma endregion Bird_Legs
   
#pragma region Bird_Nest

    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Nest_Texture);
    //glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glTranslatef(0.7f, -0.2f, 0.0f);

    glPushMatrix();

    for (int i = 0; i < 40; i++)
    {
        glTranslatef(0.0f, 0.0f, 0.05f);
        glRotatef(350.0f, 0.0f, 1.0f, 0.0f);

        //glColor3f(0.0f, 1.0f, 0.0f);
        quadric = gluNewQuadric();
        gluQuadricTexture(quadric, true);
        gluCylinder(quadric, 0.1f, 0.1f, 0.2f, 20, 20);

    }

    glPopMatrix();

    glTranslatef(-0.3f, -0.08f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

    //glColor3f(0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.4f, 0.1f, 0.2f, 20, 20);

    glTranslatef(0.0f, 0.0f, 0.15f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

#pragma endregion Bird_Nest

#pragma endregion Start

}

void Santa_Ferrari(void)
{
    glDisable(GL_TEXTURE_2D);

    //Middle Sit
    glPushMatrix();

    glColor3f(0.7f, 0.7f, 0.7f);

    glScalef(0.6f, 0.3f, 1.0f);
    quadric = gluNewQuadric();
    gluSphere(quadric, 0.5f, 20, 20);

    glPopMatrix();

    //Back (Tekayala)
    glPushMatrix();

    glTranslatef(-0.1f, 0.1f, 0.0f);

    glColor3f(1.0f, 0.7f, 0.7f);

    glScalef(0.3f, 0.6f, 1.0f);
    quadric = gluNewQuadric();
    gluSphere(quadric, 0.5f, 20, 20);

    glPopMatrix();

    //Below Sit Cover
    glPushMatrix();

    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.5f, 0.8f);
    glVertex3f(0.1f, 0.0f, -0.5f);
    glVertex3f(0.1f, 0.0f, 0.5f);
    glVertex3f(0.1f, -0.35f, 0.5f);
    glVertex3f(0.1f, -0.35f, -0.5f);

    glEnd();

    glPopMatrix();

    //Left Side big Sphere
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.5f);

    glColor3f(1.0f, 0.0f, 0.0f);

    glScalef(0.7f, 0.7f, 0.1f);
    quadric = gluNewQuadric();
    gluSphere(quadric, 0.5f, 20, 20);

    glPopMatrix();

    //Left Cover Triangle
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.5f);

    glBegin(GL_TRIANGLES);

    glVertex3f(1.0f, -0.35f, 0.0f);
    glVertex3f(0.0f, 0.35f, 0.0f);
    glVertex3f(0.0f, -0.35f, 0.0f);

    glEnd();

    glPopMatrix();

    //Left Cover Square
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.5f);

    glBegin(GL_QUADS);

    glVertex3f(-0.9f, 0.3f, 0.0f);
    glVertex3f(-0.9f, -0.35f, 0.0f);
    glVertex3f(0.0f, -0.35f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);

    glEnd();

    glPopMatrix();

    //Right Side big Sphere
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, -0.5f);

    glColor3f(1.0f, 0.0f, 0.0f);

    glScalef(0.7f, 0.7f, 0.1f);
    quadric = gluNewQuadric();
    gluSphere(quadric, 0.5f, 20, 20);

    glPopMatrix();

    //Right Cover Triangle
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.5);

    glBegin(GL_TRIANGLES);

    glVertex3f(1.0f, -0.35f, 0.0f);
    glVertex3f(0.0f, 0.35f, 0.0f);
    glVertex3f(0.0f, -0.35f, 0.0f);

    glEnd();

    glPopMatrix();

    //Right Cover Square
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.5f);
    glBegin(GL_QUADS);

    glVertex3f(-0.9f, 0.3f, 0.0f);
    glVertex3f(-0.9f, -0.35f, 0.0f);
    glVertex3f(0.0f, -0.35f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);

    glEnd();
    glPopMatrix();

    //Back Cover
    glPushMatrix();

    glBegin(GL_QUADS);

    glVertex3f(-1.0f, 0.3f, -0.5f);
    glVertex3f(-1.0f, 0.3f, 0.5f);
    glVertex3f(-1.0f, -0.35f, 0.5f);
    glVertex3f(-1.0f, -0.35f, -0.5f);

    glEnd();

    glPopMatrix();

    //Ball On Tip Left back
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-0.95f, 0.35f, 0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

    //Ball on tip Right Back
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-0.95f, 0.35f, -0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

    //Ball On Tip Left Front Top 
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, 0.35f, 0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

    //Ball On Tip Right Front Top
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, 0.35f, -0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

    //Ball On Tip Left Front Down
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, -0.35f, 0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

    //Ball On Tip Right Front Down
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, -0.35f, -0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

    //Ball On Tip Left Front Down
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.0f, -0.7f, 0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

    //Ball On Tip Right Front Down
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.0f, -0.7f, -0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

    //left Corner Curving
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-0.95f, -0.35f, 0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 0.7f, 20, 20);

    glPopMatrix();

    //left Corner Curving
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-0.95f, -0.35f, -0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 0.7f, 20, 20);

    glPopMatrix();

    //Foot Stand (Cover)
    glPushMatrix();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);

    glVertex3f(1.5f, -0.35f, 0.5f);
    glVertex3f(1.5f, -0.35f, -0.5f);
    glVertex3f(-1.0f, -0.35f, -0.5f);
    glVertex3f(-1.0f, -0.35f, 0.5f);

    glEnd();

    glPopMatrix();

    //Front Stand (Cover)
    glPushMatrix();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex3f(1.5f, 0.0f, 0.5f);
    glVertex3f(1.5f, 0.0f, -0.5f);
    glVertex3f(1.5f, -0.35f, -0.5f);
    glVertex3f(1.5f, -0.35f, 0.5f);

    glEnd();

    glPopMatrix();

    //Grill to the car (Main Big one)
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, 0.0f, -0.5f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 1.0f, 20, 20);

    glPopMatrix();

    //Small Left
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, 0.0f, -0.25f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.025f, 0.025f, 0.35f, 20, 20);

    glPopMatrix();

    //Small Right
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, 0.0f, 0.25f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.025f, 0.025f, 0.35f, 20, 20);

    glPopMatrix();

    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, 0.35f, -0.5f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 1.0f, 20, 20);

    glPopMatrix();

    //Left Corner |
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, -0.35f, 0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 0.7f, 20, 20);

    glPopMatrix();

    //Right Corner |
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, -0.35f, -0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 0.7f, 20, 20);

    glPopMatrix();

    //left corner down /
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, -0.35f, 0.5f);
    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(35.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 0.6f, 20, 20);

    glPopMatrix();

    //left corner down ---
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.0f, -0.7f, 0.5f);
    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 2.0f, 20, 20);

    glPopMatrix();

    //Middle of Down Weel
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(0.5f, -0.7f, 0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.025f, 0.025f, 0.35f, 20, 20);

    glPopMatrix();

    //Middle of Down Weel
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-0.5f, -0.7f, 0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.025f, 0.025f, 0.35f, 20, 20);

    glPopMatrix();

    //Right corner down /
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.5f, -0.35f, -0.5f);
    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(35.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 0.6f, 20, 20);

    glPopMatrix();

    //left corner down ---
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(1.0f, -0.7f, -0.5f);
    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 2.0f, 20, 20);

    glPopMatrix();

    //Middle of Down Weel
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(0.5f, -0.7f, -0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.025f, 0.025f, 0.35f, 20, 20);

    glPopMatrix();

    //Middle of Down Weel
    glPushMatrix();

    glColor3f(0.9f, 0.9f, 0.9f);
    glTranslatef(-0.5f, -0.7f, -0.5f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.025f, 0.025f, 0.35f, 20, 20);

    glPopMatrix();

}

void Santa(void)
{

#pragma region Upper_Body

    //Head
#pragma region Head
    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Santa_Face_Texture);

    glTranslatef(0.0f, 0.15f, 0.0f);

#pragma region Face

    glPushMatrix();

    glScalef(0.7f, 0.8f, 0.7f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.15f, 30, 30);

    glPopMatrix();

#pragma endregion Face    

#pragma region Mouth

    glPushMatrix();

    glTranslatef(0.0f, -0.03f, -0.11f);

    glBindTexture(GL_TEXTURE_2D, Santa_Texture);

    glScalef(2.0f, 1.0f, 1.5f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glPopMatrix();

#pragma endregion Mouth

#pragma region Eyes
   
    glDisable(GL_TEXTURE_2D);

    //Right
    glPushMatrix();

    glTranslatef(-0.04f, 0.0f, -0.09f);

    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glColor3f( 0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -0.02f);
    gluSphere(quadric, 0.005f, 20, 20);

    glPopMatrix();


    //Left
    glPushMatrix();

    glTranslatef(0.04f, 0.0f, -0.09f);

    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -0.02f);
    gluSphere(quadric, 0.005f, 20, 20);

    glPopMatrix();

    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);

#pragma endregion Eyes

#pragma region Back_head

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.03f);
    glScalef(1.1f, 1.0f, 0.8f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 30, 30);

    glPopMatrix();

#pragma endregion Back_head

#pragma region Ears
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Santa_Face_Texture);
    
    //Left Hear
    glPushMatrix();

    glTranslatef(0.105f, -0.01f, 0.0f);
    glScalef(0.8f, 0.9f, 0.7f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.035f, 30, 30);

    glPopMatrix();

    //Right Hear
    glPushMatrix();

    glTranslatef(-0.105f, -0.01f, 0.0f);
    glScalef(0.8f, 0.9f, 0.7f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.035f, 30, 30);

    glPopMatrix();

#pragma endregion Ears
  
#pragma region Cap
    //Cap

    glDisable(GL_TEXTURE_2D);
    //White Boarder of Hatt
    glTranslatef(0.0f, 0.05f, 0.0f);
    glRotatef(20.0f, 1.0f, 0.0f, 0.0f);

    glPushMatrix();

    glScalef(0.6f, 0.35f, 0.55f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.2f, 30, 30);

    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Santa_Texture);

    //Red Hatt
    glPushMatrix();

    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.1f, 0.09f, 0.15f, 20, 20);

    glTranslatef(0.0f, 0.0f, 0.14f);

    glRotatef(10.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.09f, 0.06f, 0.1f, 20, 20);

    glTranslatef(0.0f, 0.0f, 0.09f);

    glRotatef(10.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.06f, 0.0f, 0.1f, 20, 20);

    glDisable(GL_TEXTURE_2D);

    //Hatt Top Sphere
    glTranslatef(0.0f, 0.0f, 0.1f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 20, 20);

    glPopMatrix();

#pragma endregion Cap

    glPopMatrix();

#pragma endregion Head

    //Beard
#pragma region Beard
    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glTranslatef(0.0f, 0.07f, -0.09f);
    glRotatef(310.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.5f, 0.3f, 0.8f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.2f, 30, 30);
    
    glPopMatrix();

    //Button Middle 
    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glTranslatef(0.0f, -0.1f, -0.18f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 30, 30);

    glPopMatrix();

    //Button Bottom 
    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glTranslatef(0.0f, -0.2f, -0.18f);
    
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 30, 30);

    glPopMatrix();

#pragma endregion Beard
    
    //Neck, Body, Patta
#pragma region Upper_Body_Cover
    glPushMatrix();

    glTranslatef(0.0f, 0.1f, 0.0f);
    glRotatef(100.0f, 1.0f, 0.0f, 0.0f);
    glScalef(0.65f, 0.6f, 0.35f);

    //Neck
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.2f, 30, 30);

    glPopMatrix();

    glEnable(GL_TEXTURE_2D);

    //Santa Body 
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Santa_Texture);

    glPushMatrix();

    glTranslatef(0.0f, -0.15f, 0.0f);
    glScalef(0.5f, 0.6f, 0.5f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.4f, 30, 30);

    glPopMatrix();

    //Santa Kambar Patta
    glBindTexture(GL_TEXTURE_2D, Santa_Foots_Texture);

    glPushMatrix();

    glTranslatef(0.19f, -0.26f, -0.027f);
    glScalef(1.0f, 2.5f, 1.0f);

    for (size_t i = 0; i < 30; i++)
    {

        glTranslatef(0.0f, 0.0f, 0.05f);
        glRotatef(345.0f, 0.0f, 1.0f, 0.0f);


        quadric = gluNewQuadric();
        gluQuadricTexture(quadric, true);
        gluCylinder(quadric, 0.01f, 0.01, 0.07, 20, 20);

    }
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);

#pragma endregion Upper_Body_Cover

#pragma endregion Upper_Body

#pragma region Left_hand

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Santa_Texture);

    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glRotatef(15, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -0.17f, 0.0f);
    glRotatef((GLfloat)santa_sholder_Left, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.02f, 0.0f, 0.0f);

    //Main Top Sphere for joining hand And Body
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glPushMatrix();

    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.15f, 20, 20);

    glPopMatrix();


    //LBow Joint
    glPushMatrix();

    glTranslatef(0.15f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.15f, 0.0f, 0.0f);
    glRotatef((GLfloat)santa_Lbow_Left, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);

    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.15f, 20, 20);

    glPopMatrix();

    //Hands
    glBindTexture(GL_TEXTURE_2D, Santa_Foots_Texture);

    glPushMatrix();

    glTranslatef(0.15f, 0.0f, 0.0f);
    glRotatef((GLfloat)santa_Lbow_Left, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);

    glTranslatef(0.15f, 0.0f, 0.0f);
    glScalef(0.5f, 0.2f, 0.15f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

    glPopMatrix();

#pragma endregion Left_hand

#pragma region Right_hand


    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Santa_Texture);

    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glRotatef(345, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.17f, 0.0f);
    glRotatef((GLfloat)santa_sholder_Right, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.02f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glBindTexture(GL_TEXTURE_2D, Santa_Texture);
    glPushMatrix();
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.15f, 20, 20);

    glBindTexture(GL_TEXTURE_2D, Santa_Texture);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.0205f, 0.0205f, 0.15f, 20, 20);

    glPopMatrix();


    //LBow Joint
    glBindTexture(GL_TEXTURE_2D, Santa_Texture);
    glPushMatrix();

    glTranslatef(0.15f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.15f, 0.0f, 0.0f);
    glRotatef((GLfloat)santa_Lbow_Right, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);

    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.15f, 20, 20);

    glPopMatrix();



    glBindTexture(GL_TEXTURE_2D, Santa_Foots_Texture);

    glPushMatrix();

    glTranslatef(0.15f, 0.0f, 0.0f);
    glRotatef((GLfloat)santa_Lbow_Right, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);

    glTranslatef(0.15f, 0.0f, 0.0f);
    glScalef(0.5f, 0.2f, 0.15f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

    glPopMatrix();

#pragma endregion Right_hand

#pragma region Left_Leg


    glPushMatrix();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Santa_Texture);

    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.25f, -0.1f, 0.07f);
    glRotatef((GLfloat)santa_Thigh_Left, 0.0f, 1.0f, 0.0f);

    glPushMatrix();

    glTranslatef(0.05f, 0.0f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.16f, 20, 20);

    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, Santa_Foots_Texture);

    glTranslatef(0.2f, 0.0f, 0.0f);
    glRotatef((GLfloat)santa_Calf_Left, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.01f, 0.0f, 0.0f);

    glPushMatrix();

    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.15f, 20, 20);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.15f, 0.0f, 0.045f);

    glScalef(0.3f, 0.4f, 0.7f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

    glPopMatrix();

#pragma endregion Left_Leg

#pragma region Right_Leg
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Santa_Texture);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.25f, 0.1f, 0.07f);
    glRotatef((GLfloat)santa_Thigh_Right, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0.05f, 0.0f, 0.0f);
    //glScalef(1.0f, 0.2f, 0.2f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.16f, 20, 20);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, Santa_Foots_Texture);

    glTranslatef(0.2f, 0.0f, 0.0f);
    glRotatef((GLfloat)santa_Calf_Right, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.01f, 0.0f, 0.0f);

    glPushMatrix();
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.15f, 20, 20);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.15f, 0.0f, 0.045f);

    glScalef(0.3f, 0.4f, 0.7f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();


    glPopMatrix();
#pragma endregion Right_Leg

}

void Girl(void)
{
    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);

#pragma region Upper_Body

    //Head
#pragma region Head
    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glTranslatef(0.0f, 0.15f, 0.0f);
#pragma region Face

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);
    glPushMatrix();

    glScalef(0.7f, 0.8f, 0.7f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.15f, 30, 30);

    glPopMatrix();


#pragma endregion Face    

#pragma region Eyes

    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Girls_Foot_Down_Texture);

    glTranslatef(-0.04f, -0.02f, -0.09f);
    glScalef(0.1f, 0.2f, 0.1f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Girls_Foot_Down_Texture);

    glTranslatef(0.04f, -0.02f, -0.09f);
    glScalef(0.1f, 0.2f, 0.1f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

#pragma endregion Eyes

#pragma region Nose

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Girls_Nose_Texture);

    glTranslatef(0.0f, -0.065f, -0.08f);
    glScalef(0.035f, 0.025f, 0.02f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 20, 20);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.05f, 0.11f, -0.088f);
    glRotatef(330.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(20.0f, 1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(0.0f, 0.025f);
    glVertex2f(-0.025f, -0.0125f);
    glVertex2f(0.025f, -0.0125f);


    glVertex2f(0.025f, 0.0125f);
    glVertex2f(-0.025f, 0.0125f);
    glVertex2f(0.0f, -0.025f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);

    glPopMatrix();

#pragma endregion Nose

#pragma region Back_head

    glBindTexture(GL_TEXTURE_2D, Girls_Foot_Down_Texture);
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.03f);
    glScalef(1.1f, 1.0f, 0.8f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 30, 30);

    glPopMatrix();

#pragma endregion Back_head

#pragma region Ears
    //Left Hear
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);
    glTranslatef(0.105f, -0.01f, 0.0f);
    glScalef(0.8f, 0.9f, 0.7f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 30, 30);

    glPopMatrix();

    //Right Hear
    glPushMatrix();

    glTranslatef(-0.105f, -0.01f, 0.0f);
    glScalef(0.8f, 0.9f, 0.7f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 30, 30);

    glPopMatrix();

#pragma endregion Ears

#pragma region Cap
    //Cap
    glPushMatrix();
    //glBindTexture(GL_TEXTURE_2D, girl_Texture);
    glBindTexture(GL_TEXTURE_2D, Girls_Foot_Down_Texture);


    glTranslatef(0.0f, 0.06f, 0.0f);
    glRotatef(10, 1.0f, 0.0f, 0.0f);
    glScalef(0.55f, 0.6f, 0.55f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.2f, 30, 30);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f, -0.03f, 0.07f);
    glRotatef(345, 1.0f, 0.0f, 0.0f);
    glScalef(0.6f, 1.1f, 0.3f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.2f, 30, 30);

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

#pragma endregion Cap

    glPopMatrix();

#pragma endregion Head

    //Neck
#pragma region Neck

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix();

    glScalef(0.4f, 0.2f, 0.4f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.2f, 30, 30);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.05f, -0.09f, -0.04f);
    glRotatef(25.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(340.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(10.0f, 0.0f, 0.0f, 1.0f);

    glScalef(0.3f, 0.6f, 0.2f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.2f, 30, 30);

    glPopMatrix();


    glEnable(GL_TEXTURE_2D);


#pragma endregion Neck

#pragma region Main
    
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, girl_Texture);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.15f, 0.4f, 20, 20);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //

    //White Line bottom of cloth

    /*glPushMatrix();

    glTranslatef(0.19f, -0.26f, -0.027f);
    glScalef(1.0f, 2.5f, 1.0f);

    for (size_t i = 0; i < 30; i++)
    {

        glTranslatef(0.0f, 0.0f, 0.05f);
        glRotatef(345.0f, 0.0f, 1.0f, 0.0f);


        quadric = gluNewQuadric();
        gluQuadricTexture(quadric, true);
        gluCylinder(quadric, 0.01f, 0.01, 0.07, 20, 20);

    }
    glPopMatrix();*/
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
#pragma endregion Main

#pragma endregion Upper_Body

#pragma region Left_hand

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, girl_Texture);

    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glRotatef(10, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -0.1f, 0.0f);
    glRotatef((GLfloat)girl_sholder_Left, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.02f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glPushMatrix();
    
    glRotatef(90, 0.0f, 1.0f, 0.0f);

    glBindTexture(GL_TEXTURE_2D, girl_Texture);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.0205f, 0.0205f, 0.17f, 20, 20);

    glPopMatrix();


    //LBow Joint
    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glPushMatrix();
    
    glTranslatef(0.17f, 0.0f, 0.0f);
    glRotatef((GLfloat)girl_Lbow_Left, 0.0f, 1.0f, 0.0f);

    glRotatef(girl_Lbow_Bending, 0.0f, 0.0f, 1.0f);
    
    glTranslatef(0.0f, 0.0f, 0.0f);

    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.17f, 20, 20);

    glPopMatrix();

    //Hands
    glBindTexture(GL_TEXTURE_2D, Girls_Foots_Texture);

    glPushMatrix();
    
    glTranslatef(0.17f, 0.0f, 0.0f);
    glRotatef((GLfloat)girl_Lbow_Left, 0.0f, 1.0f, 0.0f);
    glRotatef(girl_Lbow_Bending, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);

    glTranslatef(0.17f, 0.0f, 0.0f);
    glScalef(0.5f, 0.2f, 0.15f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

    glPopMatrix();
#pragma endregion Left_hand

#pragma region Right_hand

    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glRotatef(350, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.1f, 0.0f);
    glRotatef((GLfloat)girl_sholder_Right, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.02f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);


    glPushMatrix();

    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, girl_Texture);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.0205f, 0.0205f, 0.17f, 20, 20);

    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);

    //LBow Joint
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.02f, 20, 20);

    glPushMatrix();

    glTranslatef(0.17f, 0.0f, 0.0f);
    glRotatef((GLfloat)girl_Lbow_Right, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);

    glPushMatrix();

    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.17f, 20, 20);
    
    //Watch
    glBindTexture(GL_TEXTURE_2D, Girls_Foot_Down_Texture);
    
    //change the girl watch position Z will take it down. Y will take in front and back
    glTranslatef(0.0f, 0.002f, 0.13f);

    //Patta
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.0205f, 0.0205f, 0.03f, 20, 20);

    glDisable(GL_TEXTURE_2D);

    //Clock
    glColor3f(1.0f * gl_fade_x, 1.0f * gl_fade_y, 0.0f * gl_fade_z);
    glTranslatef(-0.008f, 0.0f, 0.015f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.0205f, 20, 20);

    glPopMatrix();

    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Girls_Foots_Texture);

    glPushMatrix();

    glTranslatef(0.17f, 0.0f, 0.0f);
    glRotatef((GLfloat)girl_Lbow_Right, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);

    glTranslatef(0.15f, 0.0f, 0.0f);
    glScalef(0.5f, 0.2f, 0.15f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

    glPopMatrix();

#pragma endregion Right_hand

#pragma region Left_Leg

    //Before knie
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);

    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.22f, -0.07f, 0.0f);//29
    glRotatef((GLfloat)girl_Thigh_Left, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0.05f, 0.0f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.18f, 20, 20);

    glPopMatrix();

    //After knie
    glTranslatef(0.23f, 0.0f, 0.0f);
    glRotatef((GLfloat)girl_Calf_Left, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.01f, 0.0f, 0.0f);

    glPushMatrix();

    glTranslatef(-0.005f, 0.0f, 0.0f); //0.002

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.020f, 20, 20);

    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);
    glPopMatrix();

    glPushMatrix();

    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.18f, 20, 20);

    glPopMatrix();

    //Foot
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Girls_Foot_Down_Texture);

    glPushMatrix();

    glTranslatef(0.18f, 0.0f, 0.045f);

    glScalef(0.3f, 0.4f, 0.7f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

    glPopMatrix();

#pragma endregion Left_Leg

#pragma region Right_Leg
    glPushMatrix();
    
    glBindTexture(GL_TEXTURE_2D, girl_Face_Texture);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.22f, 0.07f, 0.0f);//X = 0.22;
    glRotatef((GLfloat)girl_Thigh_Right, 0.0f, 1.0f, 0.0f);

    glPushMatrix();

    glTranslatef(0.05f, 0.0f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.18f, 20, 20);
    
    glPopMatrix();

    glTranslatef(0.23f, 0.0f, 0.0f);
    glRotatef((GLfloat)girl_Calf_Right, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.01f, 0.0f, 0.0f);

    glPushMatrix();

    glTranslatef(-0.005f, 0.0f, 0.0f); //0.002
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.020f, 20, 20);

    glPopMatrix();

    glPushMatrix();
    
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.02f, 0.02f, 0.18f, 20, 20);

    glPopMatrix();

    //Foot
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Girls_Foot_Down_Texture);
    glTranslatef(0.18f, 0.0f, 0.045f);
    glScalef(0.3f, 0.4f, 0.7f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glPopMatrix();

    glPopMatrix();

#pragma endregion Right_Leg

}

void House(void)
{
    void wall(void);
    void Top_Shade(void);
    void Grill(void);
    void Windows(void);
    void Door(void);
    void Compaund(void);

#pragma region Walls

    wall();

#pragma endregion Walls
    
#pragma region Front_Triangle_Wall

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Wood_Texture);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);

    glTexCoord2f(0.2f, 0.4f);
    glVertex3f(0.0f, 3.5f, 5.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.0f, 1.8f, 5.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, 1.8f, 5.0f);

    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
#pragma endregion Front_Triangle_Wall

#pragma region Top_Chapar

    Top_Shade();

#pragma endregion Top_Chapar

#pragma region Pols
   
    Grill();

#pragma endregion Pols
        
#pragma region Windows

    Windows();

#pragma endregion Windows
        
#pragma region Doar

    Door();
#pragma endregion Doar

#pragma region Compaund

    
    glBindTexture(GL_TEXTURE_2D, Door_Texture);

    glTranslatef(15.0f, -2.0f, -10.0f);
    //back Side
    for (int i = 1; i <= 30; i++)
    {
        glTranslatef(-1.0f, 0.0f, 0.0f);
        Compaund();
    }

    //Left side
    
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    for (int i = 1; i < 30; i++)
    {
        glTranslatef(-1.0f, 0.0f, 0.0f);
        Compaund();

    }

    //Left side
    glTranslatef(0.0f, 0.0f, 30.0f);
    for (int i = 1; i < 30; i++)
    {
        glTranslatef(1.0f, 0.0f, 0.0f);
        Compaund();
    }
    

#pragma endregion Compaund

}

void Compaund(void)
{
    //front
    glBegin(GL_POLYGON);

    glTexCoord2f(0.25f, 1.5f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.5f);
    glVertex3f(-0.3f, 0.5f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.3f, -1.5f, 0.0f);
    glTexCoord2f(0.5f, 0.0f);
    glVertex3f(0.3f, -1.5f, 0.0f);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.3f, 0.5f, 0.0f);

    glEnd();

    //Right
    glBegin(GL_QUADS);

    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, 1.0f, -0.2f);
    glTexCoord2f(0.5f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.3f, 0.5f, 0.0f);
    glTexCoord2f(0.0f, 0.5f);
    glVertex3f(0.3f, 0.5f, -0.2f);

    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.3f, 0.5f, -0.2f);
    glTexCoord2f(0.5f, 0.0f);
    glVertex3f(0.3f, 0.5f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.3f, -1.5f, 0.0f);
    glTexCoord2f(0.0f, 0.5f);
    glVertex3f(0.3f, -1.5f, -0.2f);

    glEnd();

    //Middle Line 
  /* glBegin(GL_QUADS);

    //Left Border

    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, 0.1f, -0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, -0.1f, -0.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.1f, -0.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, 0.1f, -0.1f);

    ////Right
    //glTexCoord2f(1.0f, 1.0f);
    //glVertex3f(-1.25f, 2.0f, 2.2f);
    //glTexCoord2f(0.0f, 1.0f);
    //glVertex3f(-1.25f, 2.0f, 2.0f);
    //glTexCoord2f(0.0f, 0.0f);
    //glVertex3f(-1.25f, -1.5f, 2.0f);
    //glTexCoord2f(1.0f, 0.0f);
    //glVertex3f(-1.25f, -1.5f, 2.2f);

    //Left

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 1.9f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.9f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.9f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -1.9f, 2.2f);


    glEnd();
    */

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, -0.2f);

    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 1.0f, 20, 20);

    glPopMatrix();

    //Left
    glBegin(GL_QUADS);

    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, 1.0f, -0.2f);
    glTexCoord2f(0.5f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.3f, 0.5f, 0.0f);
    glTexCoord2f(0.0f, 0.5f);
    glVertex3f(-0.3f, 0.5f, -0.2f);

    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(-0.3f, 0.5f, -0.2f);
    glTexCoord2f(0.5f, 0.0f);
    glVertex3f(-0.3f, 0.5f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.3f, -1.5f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.3f, -1.5f, -0.2f);

    glEnd();

    //Back
    glBegin(GL_POLYGON);

    glTexCoord2f(0.25f, 1.5f);
    glVertex3f(0.0f, 1.0f, -0.2f);
    glTexCoord2f(0.0f, 0.5f);
    glVertex3f(-0.3f, 0.5f, -0.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.3f, -1.5f, -0.2f);
    glTexCoord2f(0.5f, 0.0f);
    glVertex3f(0.3f, -1.5f, -0.2f);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.3f, 0.5f, -0.2f);

    glEnd();
}

void wall(void)
{
    //Texturing Done
#pragma region Back_Walls

    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Wood_Texture);

    glBegin(GL_TRIANGLES);

    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(-7.0f, 4.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-7.0f, 2.0f, 2.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-7.0f, 2.0f, -2.5f);

    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(7.0f, 4.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(7.0f, 2.0f, 2.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(7.0f, 2.0f, -2.5f);

    glEnd();

    //Bottom of Triangle
    glBegin(GL_QUADS);

    //left 
    glTexCoord2f(0.0f, 0.2f);
    glVertex3f(7.0f, 2.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(6.0f, 2.0f, -2.0f);
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(6.0f, 2.0f, 2.0f);
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(7.0f, 2.0f, 2.0f);

    //Right
    glTexCoord2f(0.0f, 0.2f);
    glVertex3f(-7.0f, 2.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-6.0f, 2.0f, -2.0f);
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(-6.0f, 2.0f, 2.0f);
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(-7.0f, 2.0f, 2.0f);

    glEnd();

    glBegin(GL_QUADS);

    // Back side Wall
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-6.0f, 2.0f, -2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(6.0f, 2.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(6.0f, -3.0f, -2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-6.0f, -3.0f, -2.0f);

    //Left Side wall
    glTexCoord2f(0.6f, 0.6f);
    glVertex3f(-6.0f, 2.0f, 2.0f);
    glTexCoord2f(0.6f, 0.0f);
    glVertex3f(-6.0f, 2.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-6.0f, -3.0f, -2.0f);
    glTexCoord2f(0.0f, 0.6f);
    glVertex3f(-6.0f, -3.0f, 2.0f);

    //Right Side wall
    glTexCoord2f(0.6f, 0.6f);
    glVertex3f(6.0f, 2.0f, 2.0f);
    glTexCoord2f(0.6f, 0.0f);
    glVertex3f(6.0f, 2.0f, -2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(6.0f, -3.0f, -2.0f);
    glTexCoord2f(0.0f, 0.6f);
    glVertex3f(6.0f, -3.0f, 2.0f);


    //Front Left
    glTexCoord2f(0.6f, 0.6f);
    glVertex3f(-6.0f, 2.0f, 2.0f);
    glTexCoord2f(0.6f, 0.0f);
    glVertex3f(-1.25f, 2.0f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.25f, -2.0f, 2.0f);
    glTexCoord2f(0.0f, 0.6f);
    glVertex3f(-6.0f, -2.0f, 2.0f);

    //Front Right
    glTexCoord2f(0.6f, 0.6f);
    glVertex3f(6.0f, 2.0f, 2.0f);
    glTexCoord2f(0.6f, 0.0f);
    glVertex3f(1.25f, 2.0f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.25f, -2.0f, 2.0f);
    glTexCoord2f(0.0f, 0.6f);
    glVertex3f(6.0f, -2.0f, 2.0f);

    //Upon Door

    glTexCoord2f(0.4f, 0.4f);
    glVertex3f(-1.75f, 2.5f, 2.0f);
    glTexCoord2f(0.4f, 0.0f);
    glVertex3f(1.75f, 2.5f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.75f, 2.0f, 2.0f);
    glTexCoord2f(0.0f, 0.4f);
    glVertex3f(-1.75f, 2.0f, 2.0f);

    glEnd();

    glPopMatrix();

#pragma endregion Back_Walls
    //Texturing Done
#pragma region Ground_Wall

    glPushMatrix();
    //Ground Front Land
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, Wood_Texture);

    glBegin(GL_QUADS);

    //main Wood land
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(6.0f, -2.0f, 5.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(6.0f, -2.0f, -2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-6.0f, -2.0f, -2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-6.0f, -2.0f, 5.0f);

    //Front Small Wood Near to steps
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(6.0f, -3.0f, 5.0f);
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(6.0f, -2.0f, 5.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-6.0f, -2.0f, 5.0f);
    glTexCoord2f(0.0f, 0.2f);
    glVertex3f(-6.0f, -3.0f, 5.0f);

    //Left cover
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-6.0f, -3.0f, 5.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-6.0f, -3.0f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-6.0f, -2.0f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-6.0f, -2.0f, 5.0f);

    //Right cover
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(6.0f, -3.0f, 5.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(6.0f, -3.0f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(6.0f, -2.0f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(6.0f, -2.0f, 5.0f);

    //Steps Top 

    //Top
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -2.0f, 6.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -2.0f, 5.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.0f, -2.0f, 5.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.0f, -2.0f, 6.0f);

    //Front
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(2.0f, -2.0f, 6.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.0f, -2.0f, 6.0f);
    glTexCoord2f(0.0f, 0.2f);
    glVertex3f(-2.0f, -2.5f, 6.0f);
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(2.0f, -2.5f, 6.0f);

    //Right
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(2.0f, -2.0f, 6.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -2.0f, 5.0f);
    glTexCoord2f(0.0f, 0.2f);
    glVertex3f(2.0f, -2.5f, 5.0f);
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(2.0f, -2.5f, 6.0f);

    //Left
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(-2.0f, -2.0f, 6.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.0f, -2.0f, 5.0f);
    glTexCoord2f(0.0f, 0.2f);
    glVertex3f(-2.0f, -2.5f, 5.0f);
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(-2.0f, -2.5f, 6.0f);

    //Step Bottom

    //Top
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.0f, -2.5f, 7.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -2.5f, 5.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.0f, -2.5f, 5.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.0f, -2.5f, 7.0f);

    //Front
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(2.0f, -2.5f, 7.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.0f, -2.5f, 7.0f);
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(-2.0f, -3.0f, 7.0f);
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(2.0f, -3.0f, 7.0f);

    //Right
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(2.0f, -2.5f, 7.0f);
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(2.0f, -3.0f, 7.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, -3.0f, 5.0f);
    glTexCoord2f(0.0f, 0.2f);
    glVertex3f(2.0f, -2.5f, 5.0f);

    //Left
    glTexCoord2f(0.2f, 0.2f);
    glVertex3f(-2.0f, -2.5f, 7.0f);
    glTexCoord2f(0.2f, 0.0f);
    glVertex3f(-2.0f, -3.0f, 7.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.0f, -3.0f, 5.0f);
    glTexCoord2f(0.0f, 0.2f);
    glVertex3f(-2.0f, -2.5f, 5.0f);

    glEnd();

    glPopMatrix();

#pragma endregion Ground_Wall

#pragma region Front_Small_Walls

    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Snow_Texture);

    glBegin(GL_QUADS);

    //Top Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 3.85f, 5.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 3.85f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.0f, 2.3f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.0f, 2.3f, 5.0f);

    //Top Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0f, 3.85f, 5.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.0f, 3.85f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.0f, 2.3f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.0f, 2.3f, 5.0f);

    glEnd();

    glPopMatrix();

#pragma endregion Front_Small_Walls
    //Texturing Done
#pragma region Snow_Cylender_Poarch

    //Middle Small Cylenf=der
    glPushMatrix();

    glTranslatef(0.0f, 3.5f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 5.0f, 30, 30);

    glPopMatrix();

    //Middle Left Cylenf=der
    glPushMatrix();

    glTranslatef(2.0f, 2.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 5.0f, 30, 30);

    glPopMatrix();

    //Middle Left Cylenf=der
    glPushMatrix();

    glTranslatef(-2.0f, 2.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 5.0f, 30, 30);

    glPopMatrix();

    //Front Right Cylenf=der
    glPushMatrix();

    glTranslatef(0.0f, 3.5f, 5.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(55.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 2.5f, 30, 30);

    glPopMatrix();

    //Front Left Cylenf=der
    glPushMatrix();

    glTranslatef(0.0f, 3.5f, 5.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(305.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 2.5f, 30, 30);

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

#pragma endregion Snow_Cylender_Poarch

}

void Top_Shade(void) {
    //Texturing Done
#pragma region Left_Top_Chapar
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Snow_Texture);

    glTranslatef(-7.0f, 4.0f, 0.0f);

    glRotated(90.0f, 1.0f, 0.0f, 0.0f);
    glRotated(50.0f, 1.0f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 3.0f, 30, 30);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.0f, 4.0f, 0.0f);

    glRotated(90.0f, 1.0f, 0.0f, 0.0f);
    glRotated(310.0f, 1.0f, 0.0f, 0.0f);

    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 3.0f, 30, 30);

    glPopMatrix();

#pragma endregion Left_Top_Chapar

    //Texturing Done
#pragma region Right_Top_Chapar

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Snow_Texture);

    glTranslatef(7.0f, 4.0f, 0.0f);

    glRotated(90.0f, 1.0f, 0.0f, 0.0f);
    glRotated(50.0f, 1.0f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 3.0f, 30, 30);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.0f, 4.0f, 0.0f);

    glRotated(90.0f, 1.0f, 0.0f, 0.0f);
    glRotated(310.0f, 1.0f, 0.0f, 0.0f);

    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 3.0f, 30, 30);

    glPopMatrix();

#pragma endregion Right_Top_Chapar

    //Texturing Done
#pragma region Chapar_Main_Cylender

    glPushMatrix();

    glTranslatef(-7.0f, 4.0f, 0.0f);
    glRotated(90.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 14.0f, 30, 30);

    glPopMatrix();


    glPushMatrix();

    glRotated(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(2.3f, 2.0f, -7.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 14.0f, 30, 30);

    glPopMatrix();


    glPushMatrix();

    glRotated(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-2.3f, 2.0f, -7.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 5.0f, 30, 30);


    glTranslatef(0.0f, 0.0f, 9.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.3f, 5.0f, 30, 30);

    glPopMatrix();


    glPushMatrix();

    glBegin(GL_QUADS);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(7.0f, 4.2f, 0.2f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-7.0f, 4.2f, 0.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-7.0f, 2.2f, 2.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(7.0f, 2.2f, 2.5f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(7.0f, 4.2f, -0.2f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-7.0f, 4.2f, -0.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-7.0f, 2.2f, -2.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(7.0f, 2.2f, -2.5f);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

#pragma endregion Chapar_Main_Cylender

    //Sphere to join the shade
    //Texturing Done
#pragma region Sphere

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Snow_Texture);

    //top four Main Corners
    glPushMatrix();

    //Left Front
    glTranslatef(-7.0f, 2.02f, 2.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.3f, 30, 30);

    glPopMatrix();

    //Left back
    glPushMatrix();

    glTranslatef(-7.0f, 2.02f, -2.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.3f, 30, 30);

    glPopMatrix();

    //Right Front
    glPushMatrix();

    glTranslatef(7.0f, 2.02f, 2.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.3f, 30, 30);

    glPopMatrix();

    //Right Back
    glPushMatrix();

    glTranslatef(7.0f, 2.02f, -2.3f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.3f, 30, 30);

    glPopMatrix();

    //Right Middle 
    glPushMatrix();

    glTranslatef(7.0f, 4.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.3f, 30, 30);

    glPopMatrix();

    //Left Middle 
    glPushMatrix();

    glTranslatef(-7.0f, 4.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.3f, 30, 30);

    glPopMatrix();

    //small Shade's Corners
    //middle
    glPushMatrix();

    glTranslatef(0.0f, 3.47f, 5.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.35f, 30, 30);

    glPopMatrix();

    //Left
    glPushMatrix();

    glTranslatef(-2.1f, 2.0f, 5.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.35f, 30, 30);

    glPopMatrix();

    //Right
    glPushMatrix();

    glTranslatef(2.1f, 2.0f, 5.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.35f, 30, 30);

    glPopMatrix();


#pragma endregion Sphere

}

void Grill(void)
{
    //Front First Pols Y Big One 
   //For Incresing the hight of the grill increse 0.5 value in vise versa 
    glPushMatrix();

    glRotated(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(2.0f, 5.0f, -2.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.05f, 0.05f, 4.0f, 20, 20);

    glPopMatrix();

    glPushMatrix();

    glRotated(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(-2.0f, 5.0f, -2.0f);
    quadric = gluNewQuadric();
    gluCylinder(quadric, 0.05f, 0.05f, 4.0f, 30, 30);

    glPopMatrix();

    //Front First Pols Y Small One 

    glPushMatrix();
    glRotated(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(6.0f, 5.0f, 0.5f);
    quadric = gluNewQuadric();
    gluCylinder(quadric, 0.05f, 0.05f, 1.5f, 30, 30);

    glPopMatrix();

    glPushMatrix();
    glRotated(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(-6.0f, 5.0f, 0.5f);
    quadric = gluNewQuadric();
    gluCylinder(quadric, 0.05f, 0.05f, 1.5f, 30, 30);

    glPopMatrix();


    //Middle Verticla Pols X
    glPushMatrix();
    glRotated(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-5.0f, -0.5f, 2.0f);
    quadric = gluNewQuadric();
    gluCylinder(quadric, 0.05f, 0.05f, 4.0f, 30, 30);

    glPopMatrix();

    glPushMatrix();
    glRotated(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-5.0f, -0.5f, -6.0f);
    quadric = gluNewQuadric();
    gluCylinder(quadric, 0.05f, 0.05f, 4.0f, 30, 30);

    glPopMatrix();


    //Middle Verticla Pols Z
    glPushMatrix();
    glRotated(90.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.5f, 6.0f, 2.0f);
    quadric = gluNewQuadric();
    gluCylinder(quadric, 0.05f, 0.05f, 3.0f, 30, 30);

    glPopMatrix();

    glPushMatrix();
    glRotated(90.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.5f, -6.0f, 2.0f);
    quadric = gluNewQuadric();
    gluCylinder(quadric, 0.05f, 0.05f, 3.0f, 30, 30);

    glPopMatrix();

}

void Windows(void)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, Boarder_Texture);


#pragma region Left_Window

    //Left Window
 
    if (Black_Front_Left)
    {
        glBindTexture(GL_TEXTURE_2D, Black_Glass_Texture);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, Tree_Glass_Texture);
    }

    glBegin(GL_QUADS);

    //back Light left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.01f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, Boarder_Texture);


    glBegin(GL_QUADS);
    //Front Top Border
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, 1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.0f);

    //Front Bottom Border
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, -1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.0f);


    //Right Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);

    //left Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.9f, -1.3f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);

    //Middle of window Rods 1
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.7f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.7f, 2.0f);

    //Middle of window Rods 2
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.0f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.0f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.0f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.1f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.1f, 2.0f);

    //Middle of window Rods 3
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -0.6f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, -0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -0.7f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, -0.7f, 2.0f);

    //Middle of window Rods Vertical 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.8f, -1.2f, 2.1f);

    //Right
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.8f, -1.2f, 2.1f);

    //Left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.9f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.9f, -1.2f, 2.1f);

    glEnd();

#pragma endregion Left_Window

#pragma region Right_Window

    //Right Window

    if (Black_Front_right)
    {
        glBindTexture(GL_TEXTURE_2D, Black_Glass_Texture);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, Glass_Texture);
    }


    glBegin(GL_QUADS);

    //back Light left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.01f);

    glEnd();


    glBindTexture(GL_TEXTURE_2D, Boarder_Texture);

    glBegin(GL_QUADS);
    //Front Top Border
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.8f, 1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.0f);



    //Front Bottom Border
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, -1.2f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.0f);


    //Right Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);

    //left Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);

    //Middle of window Rods 1
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.7f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.7f, 2.0f);

    //Middle of window Rods 2
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.0f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.0f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.0f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.1f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.1f, 2.0f);

    //Middle of window Rods 3
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -0.6f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, -0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -0.7f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, -0.7f, 2.0f);

    //Middle of window Rods Vertical 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.8f, -1.2f, 2.1f);

    //Right
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.8f, -1.2f, 2.1f);

    //Left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.9f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.9f, -1.2f, 2.1f);

    glEnd();
#pragma endregion Right_Window

#pragma region Left_Side_Window

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, 4.0f);

    glRotatef(270, 0.0f, 1.0f, 0.0f);


    if (Black_Front_Left)
    {
        glBindTexture(GL_TEXTURE_2D, Black_Glass_Texture);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, Glass_Texture);
    }
    glBegin(GL_QUADS);

    //back Light Right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, -1.2f, 2.01f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, Boarder_Texture);

    glBegin(GL_QUADS);

    //Left Window
     //Front Top Border
     //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, 1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.0f);

    //Front Bottom Border
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, -1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.0f);


    //Right Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);

    //left Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.9f, -1.3f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);

    //Middle of window Rods 1
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.7f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.7f, 2.0f);

    //Middle of window Rods 2
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.0f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.0f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.0f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.1f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.1f, 2.0f);

    //Middle of window Rods 3
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -0.6f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, -0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -0.7f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, -0.7f, 2.0f);

    //Middle of window Rods Vertical 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.8f, -1.2f, 2.1f);

    //Right
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.8f, -1.2f, 2.1f);

    //Left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.9f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.9f, -1.2f, 2.1f);

    glEnd();
    glPopMatrix();


#pragma endregion Left_Side_Window

#pragma region Right_Side_Window
    glPushMatrix();
    glTranslatef(4.0f, 0.0f, 4.0f);

    glRotatef(90, 0.0f, 1.0f, 0.0f);

    if (Black_Right)
    {
        glBindTexture(GL_TEXTURE_2D, Black_Glass_Texture);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, Glass_Texture);
    }
    glBegin(GL_QUADS);

    //back Light Right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, -1.2f, 2.01f);


    glEnd();

    glBindTexture(GL_TEXTURE_2D, Boarder_Texture);


    glBegin(GL_QUADS);

    //Right Window
    //Front Top Border
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.8f, 1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.0f);



    //Front Bottom Border
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, -1.2f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.0f);


    //Right Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);

    //left Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);

    //Middle of window Rods 1
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.7f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.7f, 2.0f);

    //Middle of window Rods 2
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.0f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.0f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.0f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.1f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.1f, 2.0f);

    //Middle of window Rods 3
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -0.6f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, -0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -0.7f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, -0.7f, 2.0f);

    //Middle of window Rods Vertical 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.8f, -1.2f, 2.1f);

    //Right
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.8f, -1.2f, 2.1f);

    //Left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.9f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.9f, -1.2f, 2.1f);

    glEnd();
    glPopMatrix();


#pragma endregion Right_Side_Window

#pragma region Back_Left_Side_Window

    glPushMatrix();

    glRotatef(180, 0.0f, 1.0f, 0.0f);

    glTranslatef(7.5f, 0.0f, 0.01f);


    if (Black_Back_Left)
    {
        glBindTexture(GL_TEXTURE_2D, Black_Glass_Texture);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, Glass_Texture);
    }
    glBegin(GL_QUADS);

    //back Light Right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, -1.2f, 2.01f);


    glEnd();
    glBindTexture(GL_TEXTURE_2D, Boarder_Texture);

    glBegin(GL_QUADS);

    //Left Window

     //Front Top Border
     //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, 1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.0f);

    //Front Bottom Border
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, -1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.0f);


    //Right Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.8f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.8f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -1.2f, 2.1f);

    //left Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.9f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.9f, -1.3f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.9f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -1.2f, 2.1f);

    //Middle of window Rods 1
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.7f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.7f, 2.0f);

    //Middle of window Rods 2
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.0f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.0f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.0f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, 0.1f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, 0.1f, 2.0f);

    //Middle of window Rods 3
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -0.6f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-4.8f, -0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-2.9f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-4.8f, -0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-2.9f, -0.7f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-4.8f, -0.7f, 2.0f);

    //Middle of window Rods Vertical 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.8f, -1.2f, 2.1f);

    //Right
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.8f, -1.2f, 2.1f);

    //Left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.9f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-3.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-3.9f, -1.2f, 2.1f);

    glEnd();
    glPopMatrix();


#pragma endregion Back_Left_Side_Window

#pragma region Back_Right_Side_Window
    glPushMatrix();

    glRotatef(180, 0.0f, 1.0f, 0.0f);

    glTranslatef(-7.5f, 0.0f, 0.01f);

    if (Black_Back_Right)
    {
        glBindTexture(GL_TEXTURE_2D, Black_Glass_Texture);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, Glass_Texture);
    }

    glBegin(GL_QUADS);

    //back Light Right
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, -1.2f, 2.01f);


    glEnd();
    glBindTexture(GL_TEXTURE_2D, Boarder_Texture);


    glBegin(GL_QUADS);

    //Right Window
    //Front Top Border
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 1.2f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.8f, 1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.0f);



    //Front Bottom Border
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, -1.2f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.0f);


    //Right Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.8f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.8f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -1.2f, 2.1f);

    //left Border 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.9f, 1.3f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.9f, 1.3f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.9f, -1.3f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.9f, -1.3f, 2.1f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 1.2f, 2.01f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -1.2f, 2.01f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -1.2f, 2.1f);

    //Middle of window Rods 1
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.7f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.7f, 2.0f);

    //Middle of window Rods 2
    //front
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.0f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.0f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.0f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, 0.1f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, 0.1f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, 0.1f, 2.0f);

    //Middle of window Rods 3
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -0.6f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(4.8f, -0.6f, 2.1f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.9f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -0.6f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(4.8f, -0.6f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -0.6f, 2.0f);

    //Top
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(4.8f, -0.7f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.9f, -0.7f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.9f, -0.7f, 2.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(4.8f, -0.7f, 2.0f);

    //Middle of window Rods Vertical 
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.9f, -1.2f, 2.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.8f, -1.2f, 2.1f);

    //Right
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.8f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.8f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.8f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.8f, -1.2f, 2.1f);

    //Left
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(3.9f, 1.2f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(3.9f, 1.2f, 2.01f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(3.9f, -1.2f, 2.01f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(3.9f, -1.2f, 2.1f);

    glEnd();
    glPopMatrix();


#pragma endregion Back_Right_Side_Window

}

void Door(void)
{

#pragma region Doar_Boarder

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Boarder_Texture);

    glBegin(GL_QUADS);

    //Left Border 

    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.25f, 2.0f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.9f, 2.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.9f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.25f, -2.0f, 2.2f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.25f, 2.0f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.25f, 2.0f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.25f, -2.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.25f, -2.0f, 2.2f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, 1.9f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.9f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.9f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.0f, -1.9f, 2.2f);

    //Right Border
    //front
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.25f, 2.0f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, 1.9f, 2.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -1.9f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.25f, -2.0f, 2.2f);

    //Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.25f, 2.0f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.25f, 2.0f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.25f, -2.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.25f, -2.0f, 2.2f);

    //Left
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.9f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.0f, 1.9f, 2.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.0f, -1.9f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, -1.9f, 2.2f);


    //Front Top Border
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.25f, 2.0f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.8f, 2.2f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.8f, 2.2f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.25f, 2.0f, 2.2f);

    // //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, 1.8f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, 1.8f, 2.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, 1.8f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, 1.8f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.25f, 2.0f, 2.1f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.25f, 2.0f, 2.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.25f, 2.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.25f, 2.0f, 2.0f);

    //Front Bottom Border
    //front
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.25f, -2.0f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.25f, -2.0f, 2.2f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, -1.8f, 2.2f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.0f, -1.8f, 2.2f);

    //bottom
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1.0f, -1.8f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1.0f, -1.8f, 2.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1.0f, -1.8f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1.0f, -1.8f, 2.0f);

    //Top
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-1.25f, -2.0f, 2.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1.25f, -2.0f, 2.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1.25f, -2.0f, 2.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1.25f, -2.0f, 2.0f);

    glEnd();

    glPopMatrix();
#pragma endregion Doar_Boarder

#pragma region Main_Doar

    glPushMatrix();



    glTranslatef(-1.2f, 0.0f, 1.9f);

    glRotatef(Door_angle, 0.0f, 1.0f, 0.0f);

    glBindTexture(GL_TEXTURE_2D, Door_Texture);

    glBegin(GL_QUADS);

    //Front side
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.2f, 1.8f, 0.2f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 1.8f, 0.2f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, -1.8f, 0.2f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(2.2f, -1.8f, 0.2f);

    //right side
    glTexCoord2f(0.1f, 0.0f);
    glVertex3f(2.2f, 1.8f, 0.2f);
    glTexCoord2f(0.1f, 0.1f);
    glVertex3f(2.2f, 1.8f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(2.2f, -1.8f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(2.2f, -1.8f, 0.2f);

    //Bottom side
    glTexCoord2f(0.0f, 0.1f);
    glVertex3f(2.2f, -1.8f, 0.2f);
    glTexCoord2f(0.1f, 0.1f);
    glVertex3f(2.2f, -1.8f, 0.0f);
    glTexCoord2f(0.0f, 0.1f);
    glVertex3f(0.0f, -1.8f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, -1.8f, 0.2f);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, Steel_Texture);

    glTranslatef(1.8f, 0.0f, 0.5f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.1f, 20, 20);

    glTranslatef(0.0f, 0.0f, -0.3f);
    gluCylinder(quadric, 0.07f, 0.03f, 0.3f, 10, 10);

    glPopMatrix();

#pragma endregion Main_Doar

}

void Bushes(void)
{
    glBindTexture(GL_TEXTURE_2D, Light_Green);

    glPushMatrix();

    glTranslatef(-0.6f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);

    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, Dark_Green);

    glPushMatrix();

    glTranslatef(0.6f, 0.0f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);

    glPopMatrix();


    glBindTexture(GL_TEXTURE_2D, Dim_Green);

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.6f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);

    glPopMatrix();


    glBindTexture(GL_TEXTURE_2D, Dark_Green);
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, -0.6f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);

    glPopMatrix();


    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Light_Green);

    glTranslatef(0.3f, 0.6f, 0.4f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);

    glPopMatrix();



    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Dark_Green);

    glTranslatef(-0.3f, 0.6f, 0.4f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);

    glPopMatrix();


    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Dim_Green);

    glTranslatef(0.0f, 0.6f, -0.4f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);

    glPopMatrix();


    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, Dim_Green);

    glTranslatef(0.0f, 1.2f, 0.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 30, 30);

    glPopMatrix();
}

void House_Tree(void)
{
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, tree_Trunk);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.1f, 0.1f, 0.5f, 20, 20);

    glTranslatef(0.0f, 0.0f, 0.3f);

    glBindTexture(GL_TEXTURE_2D, Dark_Green);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.1f, 0.5f, 20, 20);

    glTranslatef(0.0f, 0.0f, 0.3f);

    glBindTexture(GL_TEXTURE_2D, Dim_Green);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.1f, 0.5f, 20, 20);

    glTranslatef(0.0f, 0.0f, 0.3f);

    glBindTexture(GL_TEXTURE_2D, Light_Green);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.0f, 0.5f, 20, 20);

    glDisable(GL_TEXTURE_2D);
    glTranslatef(0.0f, 0.0f, 0.25f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.15f, 0.0f, 0.3f, 20, 20);


    glPopMatrix();
}

void Tree(void)
{
    //Bark Began
#pragma region Bark_Texture

   //(Bark)Khod left
    glPushMatrix();

    glTranslatef(-0.12f, 0.0f, 2.5f);
    glRotatef(20.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.15f, 0.1f, 1.0f, 15, 15);

    glPopMatrix();

    //(Bark)Khod left
    glPushMatrix();

    glTranslatef(-0.12f, 0.0f, 2.5f);
    glRotatef(340.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.15f, 0.1f, 1.0f, 15, 15);

    glPopMatrix();

    //(Bark)Khod Fifth
    glPushMatrix();

    glTranslatef(-0.05f, 0.0f, 1.55f);
    glRotatef(357.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.2f, 0.15f, 1.0f, 15, 15);


    //Sub Bark
    glTranslatef(0.0f, 0.0f, 0.5f);
    glRotatef(300.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.15f, 0.1f, 0.8f, 15, 15);

    glTranslatef(0.0f, 0.0f, 0.75f);
    glRotatef(10.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.1f, 0.1f, 0.4f, 15, 15);

    glTranslatef(0.0f, 0.0f, 0.35f);
    glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.1f, 0.1f, 0.4f, 15, 15);

    glPopMatrix();

    //(Bark)Khod Forth
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.59f);
    glRotatef(357.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.2f, 1.0f, 15, 15);


    //Sub bark
    glTranslatef(0.0f, 0.0f, 0.59f);
    glRotatef(60.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.25f, 0.2f, 1.0f, 15, 15);


    glTranslatef(0.0f, 0.0f, 0.95f);
    glRotatef(350.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.2f, 0.15f, 1.0f, 15, 15);

    glTranslatef(0.0f, 0.0f, 0.95f);
    glRotatef(350.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.15f, 0.1f, 0.7f, 15, 15);


    glPopMatrix();


    //Khod Third 
    glPushMatrix();

    glTranslatef(0.09f, 0.0f, -0.4f);
    glRotatef(355.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.4f, 0.3f, 1.0f, 15, 15);


    //Sub bark
    glTranslatef(0.0f, 0.0f, 0.75f);
    glRotatef(300.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.3f, 0.25f, 1.0f, 15, 15);


    glTranslatef(0.0f, 0.0f, 0.88f);
    glRotatef(20.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.27f, 0.15f, 1.0f, 15, 15);

    glTranslatef(0.0f, 0.0f, 0.95f);
    glRotatef(20.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.15f, 0.1f, 1.0f, 15, 15);

    glPopMatrix();

    //Khod  Second
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, -1.3f);
    glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.5f, 0.4f, 1.0f, 15, 15);

    glPopMatrix();

    //Khod Bottom 
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, -2.3f);
    //glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.6f, 0.48f, 1.2f, 15, 15);

    glPopMatrix();

#pragma endregion Bark_Texture

    //Leaf Began 
#pragma region Leaf_Texture

    //Bark Right
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Leaf_Texture);
    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 3.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.8f, 30, 30);

    glPopMatrix();

    //Bark Left
    glPushMatrix();

    glTranslatef(-2.0f, 0.0f, 3.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.8f, 30, 30);

    glPopMatrix();

    //Bark Big One
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, Leaf_Texture);
    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 5.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 1.0f, 30, 30);


    glTranslatef(0.55f, 1.23f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 1.0f, 30, 30);

    glTranslatef(-0.9f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 1.0f, 30, 30);

    glPopMatrix();

    //Middle Left 
    glPushMatrix();

    glTranslatef(0.65f, 0.0f, 4.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.9f, 30, 30);

    glPopMatrix();

    //Middle Right 
    glPushMatrix();

    glTranslatef(-0.65f, 0.0f, 4.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.9f, 30, 30);

    glPopMatrix();


    //Middle back
    glPushMatrix();

    glTranslatef(0.0f, 1.3f, 3.7f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.9f, 30, 30);

    glPopMatrix();


#pragma endregion Leaf_Texture    

   
}

void Sky(void)
{
    
    glBindTexture(GL_TEXTURE_2D, Sky_Texture);

    glBegin(GL_QUADS);

    //Top
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-50.0f, 20.0f, -50.0f);
    glTexCoord2f(50.0f, 0.0f);
    glVertex3f(-50.0f, 20.0f, 50.0f);
    glTexCoord2f(50.0f, 50.0f);
    glVertex3f(50.0f, 20.0f, 50.0f);
    glTexCoord2f(0.0f, 100.0f);
    glVertex3f(50.0f, 20.0f, -50.0f);
    

    //Back Side
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-50.0f, 20.0f, -50.0f);
    glTexCoord2f(50.0f, 0.0f);
    glVertex3f(-50.0f, -30.0f, -50.0f);
    glTexCoord2f(50.0f, 50.0f);
    glVertex3f(50.0f, -30.0f, -50.0f);
    glTexCoord2f(0.0f, 100.0f);
    glVertex3f(50.0f, 20.0f, -50.0f);

    //Back Side
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-50.0f, 20.0f, 50.0f);
    glTexCoord2f(50.0f, 0.0f);
    glVertex3f(-50.0f, -30.0f, 50.0f);
    glTexCoord2f(50.0f, 50.0f);
    glVertex3f(50.0f, -30.0f, 50.0f);
    glTexCoord2f(0.0f, 100.0f);
    glVertex3f(50.0f, 20.0f, 50.0f);

    //Left Side
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-50.0f, 20.0f, -50.0f);
    glTexCoord2f(50.0f, 0.0f);
    glVertex3f(-50.0f, -30.0f, -50.0f);
    glTexCoord2f(50.0f, 50.0f);
    glVertex3f(-50.0f, -30.0f, 50.0f);
    glTexCoord2f(0.0f, 100.0f);
    glVertex3f(-50.0f, 20.0f, 50.0f);

    //Right Side
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(50.0f, 20.0f, -50.0f);
    glTexCoord2f(50.0f, 0.0f);
    glVertex3f(50.0f, -30.0f, -50.0f);
    glTexCoord2f(50.0f, 50.0f);
    glVertex3f(50.0f, -30.0f, 50.0f);
    glTexCoord2f(0.0f, 100.0f);
    glVertex3f(50.0f, 20.0f, 50.0f);


    glEnd();
   
}

void Land(void)
{
    glBindTexture(GL_TEXTURE_2D, Snow_Texture);

    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-50.0f, -1.0f, -50.0f);
    glTexCoord2f(100.0f, 0.0f);
    glVertex3f(-50.0f, -1.0f, 50.0f);
    glTexCoord2f(100.0f, 100.0f);
    glVertex3f(50.0f, -1.0f, 50.0f);
    glTexCoord2f(0.0f, 100.0f);
    glVertex3f(50.0f, -1.0f, -50.0f);

    glEnd();

    glDisable(GL_TEXTURE_2D);

    
    //Eyes
    //Left Side
    glPushMatrix();

    glTranslatef(-9.8f, 2.2f, 7.45f);
    glColor3f(0.0f, 0.0f, 0.0f );
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 10, 10);

    glTranslatef(-0.4f, 0.0f, 0.0f);
    gluSphere(quadric, 0.05f, 10, 10);

    glPopMatrix();
    
    //Right Side
    glPushMatrix();

    glTranslatef(9.8f, 2.2f, 7.45f);
    glColor3f(0.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.05f, 10, 10);

    glTranslatef(0.4f, 0.0f, 0.0f);
    gluSphere(quadric, 0.05f, 10, 10);

    glPopMatrix();

    //Nose Right
    glPushMatrix();

    glTranslatef(10.0f, 1.9f, 7.5f);
    glColor3f(1.0f * gl_fade_x, 0.5f * gl_fade_y, 0.0f * gl_fade_z);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.07f, 0.0f, 0.5f, 10, 10);

    //Left
    glTranslatef(-20.0f, 0.0f, 0.0f);
    gluCylinder(quadric, 0.07f, 0.0f, 0.5f, 10, 10);

    glPopMatrix();

    //Snow Man Hands Right
    glPushMatrix();
    glColor3f(1.0f * gl_fade_x, 0.5f * gl_fade_y, 0.5f * gl_fade_z);

    glTranslatef(10.5f, 1.2f, 7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.07f, 0.04f, 1.0f, 10, 10);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(9.5f, 1.2f, 7.0f);
    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.07f, 0.04f, 1.0f, 10, 10);

    glPopMatrix();

    //Snow Man Hands Left
    glPushMatrix();

    glTranslatef(-10.5f, 1.2f, 7.0f);
    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.07f, 0.04f, 1.0f, 10, 10);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-9.5f, 1.2f, 7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluCylinder(quadric, 0.07f, 0.04f, 1.0f, 10, 10);

    glPopMatrix();

    //Body
    if (print)
    {
        glEnable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        glEnable(GL_LIGHTING);
    }
    else
        glDisable(GL_LIGHTING);
    
    glColor3f(gl_fade_x, gl_fade_x, gl_fade_x);

    glPushMatrix();

    glTranslatef(10.0f, 2.0f, 7.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 40, 40);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(10.0f, 1.0f, 7.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.75f, 40, 40);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(10.0f, -0.5f, 7.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 1.0f, 40, 40);

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-10.0f, 2.0f, 7.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.5f, 40, 40);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-10.0f, 1.0f, 7.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 0.75f, 40, 40);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-10.0f, -0.5f, 7.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 1.0f, 40, 40);

    glPopMatrix();

    glPushMatrix();


    glDisable(GL_LIGHTING);
    glPopMatrix();
}

GLvoid KillFont(GLvoid)                     // Delete The Font
{
    glDeleteLists(base, 256);               // Delete All 256 Characters
}

void unInitialize()
{
    //Local Variable for Freeing the Queue Objects
    struct Snow* Temp = NULL, * Prev = NULL;
    struct Snow* Temp_2 = NULL, * Prev_2 = NULL;
    struct Snow* Temp_3 = NULL, * Prev_3 = NULL;
    struct Snow* Temp_4 = NULL, * Prev_4 = NULL;
    Temp = Front;
    Temp_2 = Front_2;
    Temp_3 = Front_3;
    Temp_4 = Front_4;


    int i = 1;

    //code
    if (gdFullScreen_DM == TRUE)
    {
        dwStyle_D = GetWindowLong(ghwnd_DM, GWL_STYLE);
        SetWindowLong(ghwnd_DM, GWL_STYLE, (dwStyle_D | WS_OVERLAPPEDWINDOW));
        SetWindowPlacement(ghwnd_DM, &wpPrev_DM);
        SetWindowPos(ghwnd_DM, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
        ShowCursor(TRUE);
    }

    //Front 1
    while (i <= 10)
    {
        while (Temp->Next != NULL)
        {
            Prev = Temp;
            Temp = Temp->Next;
        }
        free(Temp);
        Prev->Next = NULL;
        Temp = Front;

        i++;
    }

    //Front 2
    while (i <= 10)
    {
        while (Temp_2->Next != NULL)
        {
            Prev_2 = Temp_2;
            Temp_2 = Temp_2->Next;
        }
        free(Temp_2);
        Prev_2->Next = NULL;
        Temp_2 = Front;

        i++;
    }

    //Front 3
    while (i <= 10)
    {
        while (Temp_3->Next != NULL)
        {
            Prev_3 = Temp_3;
            Temp_3 = Temp_3->Next;
        }
        free(Temp_3);
        Prev_3->Next = NULL;
        Temp_3 = Front;

        i++;
    }

    //Front 4
    while (i <= 10)
    {
        while (Temp_4->Next != NULL)
        {
            Prev_4 = Temp_4;
            Temp_4 = Temp_4->Next;
        }
        free(Temp_4);
        Prev_4->Next = NULL;
        Temp_4 = Front;

        i++;
    }

    if (base)
    {
        KillFont();
    }
    if (wglGetCurrentContext() == ghrc_DM)
    {
        wglMakeCurrent(NULL, NULL);
    }

    if (ghrc_DM)
    {
        wglDeleteContext(ghrc_DM);
        ghrc_DM = NULL;
    }

    if (ghdc_DM)
    {
        ReleaseDC(ghwnd_DM, ghdc_DM);
        ghdc_DM = NULL;
    }

    if (quadric)
    {
        gluDeleteQuadric(quadric);
        quadric = NULL;
    }

    if (gpFile_DM)
    {
        fclose(gpFile_DM);
        gpFile_DM = NULL;
    }

}
