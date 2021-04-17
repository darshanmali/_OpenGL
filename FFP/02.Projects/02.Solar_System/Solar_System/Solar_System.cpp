#include<windows.h>
#include"Header.h"
#include<gl/GL.h>
#include<stdio.h>
#include<gl/GLU.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>


#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"Glu32.lib")
#pragma comment(lib,"Winmm.lib") /*For sound API's */
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"kernel32.lib")
#pragma comment(lib,"user32.lib")

#define WIN_WIDTH_DM 800
#define WIN_HEIGHT_DM 600

#define IMG_WIDTH_DM 128
#define IMG_HEIGHT_DM 128

#define ROTATION_FROM_SUN       101
#define ROTATION_FROM_RADIAL    102



/* *******************************Environmental Variables & fuctions *********************** */

// Global Variables Declaration 
DWORD dwStyle_D;
WINDOWPLACEMENT wpPrev_DM = { sizeof(WINDOWPLACEMENT) };
bool gdFullScreen_DM = false;
HWND ghwnd_DM = NULL;
bool gbActiveWindows_DM = false;
HDC ghdc_DM = NULL;
HGLRC ghrc_DM = NULL;
FILE* gpFile_DM = NULL;
//GLfloat scane_2_angle_DM = 0.0f;
static GLfloat x = 0.0;

bool start = false;
bool scene_1 = false;
bool scene_2 = false;
bool scene_3 = false;
bool scene_4 = false;
bool scene_5 = false;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Resize(int, int);
void unInitialize(void);
void Display(void);

/* *******************Font variables **************** */
HINSTANCE hInstance;
GLuint  base;
GLYPHMETRICSFLOAT gmf[256];
GLfloat fColor_x_DM = 0.0f;
GLfloat fColor_y_DM = 0.0f;
GLfloat fColor_z_DM = 0.0f;

GLvoid BuildFont(GLvoid);
GLvoid Print_Font(const char*, ...);
GLvoid KillFont(GLvoid);


/* *******************Scene 1 variables ( Effect ) **************** */

bool play_sound = false;
bool forword = false;
GLfloat Sphere_Z = 80.0f;

int rand_val[20];
GLfloat rand_1_Z = -40.0f;
GLfloat rand_2_Z = -40.0f;
GLfloat rand_3_Z = -40.0f;

GLfloat Incre_1 = 0.075f;
GLfloat Incre_2 = 0.075f;
GLfloat Incre_3 = 0.075f;

bool flag_first = true;
bool flag_second = false;
bool flag_third = false;


/*  *********************** Scene 2 for Sun ************************ */
//Frame Buffer Fuction 
void CreateTexture(GLuint*);
void scane_2_RenderToTexture(int);
void scane_2_Drow_Model(int);
void ViewOrtho(void);
void ViewPerspective(void);
void scane_2_Radial_Effect(int times, float inc);

GLfloat scane_2_angle_DM = 360.0f;
GLfloat radial_scane_2_angle_DM = 360.0f;
GLfloat Mercury_scane_2_angle_DM = 250.0f;
GLfloat Venus_scane_2_angle_DM = 180.0f;
GLfloat Earth_scane_2_angle_DM = 230.0f;
GLfloat Moon_scane_2_angle_DM = 280.0f;
GLfloat Mars_scane_2_angle_DM = 360.0f;
GLfloat Jupitor_scane_2_angle_DM = 310.0f;
GLfloat Saturn_scane_2_angle_DM = 170.0f;
GLfloat Uranus_scane_2_angle_DM = 120.0f;
GLfloat Neptune_scane_2_angle_DM = 90.0f;
GLfloat Pluto_scane_2_angle_DM = 300.0f;
GLfloat scane_2_Earth_angle = 360.0f;
GLfloat scane_2_Moon_angle = 360.0f;

GLUquadric* quadric = NULL;
HBITMAP hBitmap;
BITMAP bmp;

GLuint winWidth = 0;
GLuint winHeight = 0;

int Timer = 3000;
int planet_count = 0;

GLuint Texture_ID;

GLuint Sun_Texture_DM;
GLuint Mercury_Texture_DM;
GLuint Venus_Texture_DM;
GLuint Earth_Texture_DM;
GLuint Moon_Texture_DM;
GLuint Mars_Texture_DM;
GLuint Jupiter_Texture_DM;
GLuint Saturn_Texture_DM;
GLuint Saturn_Ring_Texture_DM;
GLuint Uranus_Texture_DM;
GLuint Neptune_Texture_DM;
GLuint Pluto_Texture_DM;

bool SUN = false;
bool MERCURY = false;
bool VENUS = false;
bool EARTH = false;
bool MARS = false;
bool JUPITOR = false;
bool SATURN = false;
bool URANUS = false;
bool NEPTUNE = false;
bool PLUTO = false;

void scane_2_Sun_rotation(int);

/*  *********************** Scene 3 for Solar ************************ */

GLfloat rotate_cube_DM = 0.0f;
GLfloat val = 0.01f;

GLfloat z = 6.0f;

GLfloat angle_DM = 360.0f;
GLfloat radial_angle_DM = 360.0f;
GLfloat Mercury_angle_DM = 360.0f;
GLfloat Venus_angle_DM = 180.0f;
GLfloat Earth_angle_DM = 30.0f;
GLfloat Moon_angle_DM = 280.0f;
GLfloat Mars_angle_DM = 270.0f;
GLfloat Jupitor_angle_DM = 100.0f;
GLfloat Saturn_angle_DM = 330.0f;
GLfloat Uranus_angle_DM = 220.0f;
GLfloat Neptune_angle_DM = 90.0f;
GLfloat Pluto_angle_DM = 300.0f;
GLfloat Earth_angle = 360.0f;
GLfloat Moon_angle = 360.0f;
//Lighting variables 
bool gbLight = true;
bool Camera_position_Forword = true;
bool Camera_position_Backword = false;

GLfloat lAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat lDefues[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat lPosition[] = { 0.0f, 0.0f, 5.0f, 1.0f };

GLfloat lights_Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat l_2_Ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat l_2_Defues[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat l_2_Position[] = { 20.0f, 0.0f, 15.0f, 1.0f };

GLfloat lights_2_Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };


void Sun_rotation(int);
void Drow_Model(int);
void RenderToTexture(int);

/*  *********************** Scene 4 for AstorMediComp ************************ */

GLuint Master_DM;

GLuint  base_scene_4;
GLYPHMETRICSFLOAT gmf_scene_4[256];

GLfloat flAmbient[] = { 1.0f, 0.5f, 1.0f, 1.0f };
GLfloat flDefues[] = { 0.6f, 0.5f, 1.0f, 1.0f };
GLfloat flPosition[] = { 70.0f, 60.0f, 80.0f, 1.0f };
GLfloat flights_Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat fmaterial_Ambient[] = { 0.5f, 0.3f, 0.7f, 1.0f };
GLfloat fmaterial_Diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat fmaterial_Specular[] = { 1.0f, 0.0f, 0.5f, 1.0f };

GLfloat fmaterial_Shininess = 60.0f;

GLfloat camera_Z_for_scene_4;

GLfloat Scene_4_Y = 0.0f;

bool Print_A = false;
bool Print_S = false;
bool Print_T = false;
bool Print_R = false;
bool Print_O = false;
bool Print_M = false;
bool Print_E = false;
bool Print_D = false;
bool Print_I = false;
bool Print_C = false;
bool Print_C_O = false;
bool Print_C_M = false;
bool Print_P = false;

bool Translate_scene_4 = false;

bool Move_Again = false;
GLfloat Inc = 0.0f;
GLint Alfabet_Counter = 0;
GLvoid BuildFont_scene_4(GLvoid);
GLvoid Print_Font_scene_4(const char*, ...);
GLvoid KillFont_scene_4(GLvoid);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreIntance, LPSTR lpszCmdLine, int iCmdShow)
{
    //Function 

    void Initialize(void);

    WNDCLASSEX wndclassex;
    HWND hwnd;
    MSG msg;
    TCHAR Appname[] = TEXT("MY_Solar");
    bool bDone = false;
    INT x = 0, y = 0;
    INT Width = 800;
    INT Height = 600;

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
        TEXT("MY Solar System !"),
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
    //Function
    void FullScreen(void);

    switch (iMsg)
    {
    case WM_PAINT:
        FullScreen();
        start = true;
        break;
    case WM_TIMER:
        KillTimer(hwnd, MYTIMER);
        KillTimer(hwnd, MYAMCTIMER);

        if (planet_count <= 11)
        {
            planet_count++;
        }
        
        if (scene_4)
        {
            if (Alfabet_Counter < 14)
            {
                Alfabet_Counter++;
            }
        }

        switch (planet_count)
        {
        case 1:
            
            SUN = true;
            SetTimer(hwnd, MYTIMER, 3600, NULL);
            break;
        case 2:
            
            SUN = false;
            MERCURY = true;
            SetTimer(hwnd, MYTIMER, 2000, NULL);
            break;
        case 3:
            
            MERCURY = false;
            VENUS = true;
            SetTimer(hwnd, MYTIMER, 1500, NULL);
            break;
        case 4:
            VENUS = false;
            EARTH = true;
            SetTimer(hwnd, MYTIMER, 1800, NULL);
            break;
        case 5:
            EARTH = false;
            MARS = true;
            SetTimer(hwnd, MYTIMER, 1800, NULL);
            break;
        case 6:
            MARS = false;
            JUPITOR = true;
            SetTimer(hwnd, MYTIMER, 2000, NULL);
            break;
        case 7:
            JUPITOR = false;
            SATURN = true;
            SetTimer(hwnd, MYTIMER, 2200, NULL);
            break;
        case 8:
            SATURN = false;
            URANUS = true;
            SetTimer(hwnd, MYTIMER, 1900, NULL);
            break;
        case 9:
            URANUS = false;
            NEPTUNE = true;
            SetTimer(hwnd, MYTIMER, 1800, NULL);
            break;
        case 10:
            NEPTUNE = false;
            PLUTO = true;
            SetTimer(hwnd, MYTIMER, 1800, NULL);
            break;
        case 11: 
            PLUTO = false;
            scene_2 = false;
            glEnable(GL_LIGHT1);
            glDisable(GL_LIGHT2);
            scene_3 = true;
            break;
        }

        switch (Alfabet_Counter)
        {
        case 1:
            Print_A = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 2:
            Print_S = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 3:
            Print_T = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 4:
            Print_R = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 5:
            Print_O = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 6:
            Print_M = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 7:
            Print_E = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 8:
            Print_D = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 9:
            Print_I = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 10:
            Print_C = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 11:
            Print_C_O = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 12:
            Print_C_M = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        case 13:
            Print_P = true;
            SetTimer(hwnd, MYAMCTIMER, 2000, NULL);
            break;
        default:
            break;
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

        case VK_UP:
            Scene_4_Y += 0.005f;
            fprintf_s(gpFile_DM, "\nscane_4_Y = %f\n\n", Scene_4_Y);
            break;
        case VK_DOWN:
            Scene_4_Y -= 0.005f;
            fprintf_s(gpFile_DM, "\nscane_4_Y = %f\n\n", Scene_4_Y);
            break;
        case VK_SPACE:
           
            break;
        case VK_ESCAPE:
            DestroyWindow(hwnd);
            break;
        }
        break;
    case WM_SIZE:
        Resize(LOWORD(lParam), HIWORD(lParam));
        winWidth = LOWORD(lParam);
        winHeight = HIWORD(lParam);
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

void FullScreen()
{
    MONITORINFO mi_D = { sizeof(MONITORINFO) };

    dwStyle_D = GetWindowLong(ghwnd_DM, GWL_STYLE);
    if (dwStyle_D & WS_OVERLAPPEDWINDOW)
    {
        if (GetMonitorInfo(MonitorFromWindow(ghwnd_DM, MONITORINFOF_PRIMARY), &mi_D))
        {
            SetWindowLong(ghwnd_DM, GWL_STYLE, (dwStyle_D & ~WS_OVERLAPPEDWINDOW));
            SetWindowPos(ghwnd_DM, HWND_TOP, mi_D.rcMonitor.left, mi_D.rcMonitor.top, mi_D.rcMonitor.right - mi_D.rcMonitor.left, mi_D.rcMonitor.bottom - mi_D.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED); // SWP_FRAMECHANGED = WM_NCCALCSIZE      
        }
    }
    ShowCursor(FALSE);
 }

void Initialize()
{

    //Local Fuction 
    bool LoadTexture(GLuint*, TCHAR[]);

    PIXELFORMATDESCRIPTOR pfd_DM;
    int iPixelFormatIndex_DM;

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

    /*  Start   */
#pragma region Start

    /*Building the font */
    BuildFont();

#pragma endregion Start

    /*  Scene First 1   */
#pragma region Scene_First

    //rand 1
    int j = 0;
    while (j < 20)
    {
        rand_val[j] = 1 - rand() % 10;
        j++;
    }

#pragma endregion Scene_First    

    /*  Scene Second 2  */
#pragma region Section_Second

    /*call to create texture */
    CreateTexture(&Texture_ID);

    LoadTexture(&Sun_Texture_DM, MAKEINTRESOURCE(MYSUN));
    LoadTexture(&Mercury_Texture_DM, MAKEINTRESOURCE(MYMERCURY));
    LoadTexture(&Venus_Texture_DM, MAKEINTRESOURCE(MYVENUS));
    LoadTexture(&Earth_Texture_DM, MAKEINTRESOURCE(MYEARTH));
    LoadTexture(&Moon_Texture_DM, MAKEINTRESOURCE(MYMOON));
    LoadTexture(&Mars_Texture_DM, MAKEINTRESOURCE(MYMARS));
    LoadTexture(&Jupiter_Texture_DM, MAKEINTRESOURCE(MYJUPITER));
    LoadTexture(&Saturn_Texture_DM, MAKEINTRESOURCE(MYSATURN));
    LoadTexture(&Uranus_Texture_DM, MAKEINTRESOURCE(MYURANUS));
    LoadTexture(&Neptune_Texture_DM, MAKEINTRESOURCE(MYNEPTUNE));
    LoadTexture(&Pluto_Texture_DM, MAKEINTRESOURCE(MYPLUTO));
    LoadTexture(&Saturn_Ring_Texture_DM, MAKEINTRESOURCE(MYSATURNRING));

#pragma endregion Section_Second

    /*  Scene Second 3  */
#pragma region Section_Third

    //Lights
    glLightfv(GL_LIGHT1, GL_AMBIENT, lAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lDefues);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lights_Specular);
    glLightfv(GL_LIGHT1, GL_POSITION, lPosition);

    glLightfv(GL_LIGHT2, GL_AMBIENT, l_2_Ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, l_2_Defues);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lights_2_Specular);
    glLightfv(GL_LIGHT2, GL_POSITION, l_2_Position);



#pragma endregion Section_Third

    /*  Scene Second 4  */
#pragma region Section_Fourth

    LoadTexture(&Master_DM, MAKEINTRESOURCE(MYSIR));

    glLightfv(GL_LIGHT3, GL_AMBIENT, flAmbient);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, flDefues);
    glLightfv(GL_LIGHT3, GL_SPECULAR, flights_Specular);
    glLightfv(GL_LIGHT3, GL_POSITION, flPosition);

    BuildFont_scene_4();

#pragma endregion Section_Fourth

    Resize(WIN_WIDTH_DM, WIN_HEIGHT_DM);

}

void CreateTexture(GLuint* Texture_n)
{
    GLuint* data;

    data = (GLuint*)malloc((IMG_HEIGHT_DM * IMG_WIDTH_DM) * 4 * sizeof(GLuint));
    if (data == NULL)
    {
        fprintf_s(gpFile_DM, "Unable to Allocated Memeory...!!!\n");
        exit(1);
    }
    ZeroMemory(data, ((IMG_WIDTH_DM * IMG_HEIGHT_DM) * 4 * sizeof(GLuint)));

    glGenTextures(1, Texture_n);
    glBindTexture(GL_TEXTURE_2D, *Texture_n);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, 128, 128, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, data);           // Build Texture Using Information In data

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    free(data);

}

bool LoadTexture(GLuint* Texture, TCHAR Resource_ID[])
{
    bool bResult = false;
    hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), Resource_ID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
    if (hBitmap != NULL)
    {
        bResult = true;
        GetObject(hBitmap, sizeof(BITMAP), &bmp);

        //From here We are Starting the Texturing Code
        glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
        glGenTextures(1, Texture);
        glBindTexture(GL_TEXTURE_2D, *Texture);
        //Setting Texture Param
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);
        DeleteObject(hBitmap);
    }
    return (bResult);

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

void Display(void)
{
    /* Local fuction */
#pragma region Scene_1
    void stars(GLfloat, GLfloat, GLfloat);
#pragma endregion Scene_1
    /*Scene 2 functions */
#pragma region Scene_2
    void scane_2_sun(void);
    void scane_2_Mercury(void);
    void scane_2_Venus(void);
    void scane_2_Earth(void);
    void scane_2_Mars(void);
    void scane_2_Jupitor(void);
    void scane_2_Saturn(void);
    void scane_2_Uranus(void);
    void scane_2_Neptune(void);
    void scane_2_Pluto(void);
#pragma endregion Scene_2
    /*Scene 3 functions */
#pragma region Scene_3

    void sun(void);
    void Mercury(void);
    void Venus(void);
    void Earth(void);
    void Mars(void);
    void Jupiter(void);
    void Saturn(void);
    void Uranus(void);
    void Neptune(void);
    void Pluto(void);
   
#pragma endregion Scene_3

    void update(void);

    //code
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    if (start)
    {
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glPushMatrix();
        glColor3f(fColor_x_DM, fColor_y_DM, fColor_z_DM);
        glTranslatef(-3.0f, 0.0f, -5.0f);
        Print_Font("AstroMediComp ");
        glTranslatef(-3.0f, -1.0f, 0.0f);
        Print_Font("Presents... ");
        glPopMatrix();

        glPopMatrix();
    }
    else if (scene_1)
    {
        if (!play_sound)
        {
            PlaySound("Sound_track.wav", NULL, SND_ASYNC);
            play_sound = true;
        }
        glPushMatrix();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(0.0f, 0.0f, -20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        /*( - ) is on Right side
          ( + ) is on Left side*/

        if (flag_first)
        {
#pragma region First_Top

            /*This is Left side */
            stars(20.0f, 20.0f, rand_1_Z);
            /*This is Left side */
            stars(20.0f, 15.0f, rand_1_Z);
            /*This is Left side */
            stars(10.0f, 10.0f, rand_1_Z);
            /*This is Center side */
            stars(0.0f, 20.0f, rand_1_Z);
            stars(0.0f, 5.0f, rand_1_Z);
            stars(0.0f, -20.0f, rand_1_Z);
            /*This is Right side */
            stars(-10.0f, 10.0f, rand_1_Z);
            /*This is Right side */
            stars(-20.0f, 15.0f, rand_1_Z);
            /*This is Right side */
            stars(-20.0f, 20.0f, rand_1_Z);

#pragma endregion First_Top

#pragma region First_Middle

            /*This is Left side */
            stars(20.0f, 0.0f, rand_1_Z);
            /*This is Left side */
            stars(10.0f, 0.0f, rand_1_Z);
            /*This is Center side */
            stars(0.0f, 0.0f, rand_1_Z);
            /*This is Right side */
            stars(-10.0f, 0.0f, rand_1_Z);
            /*This is Right side */
            stars(-20.0f, 0.0f, rand_1_Z);

#pragma endregion First_Middle

#pragma region First_Bottom


            /*This is Left side */
            stars(20.0f, -15.0f, rand_1_Z);
            /*This is Left side */
            stars(10.0f, -10.0f, rand_1_Z);
            /*This is Center side */
            stars(0.0f, 5.0f, rand_1_Z);
            stars(0.0f, -20.0f, rand_1_Z);
            /*This is Right side */
            stars(-10.0f, -10.0f, rand_1_Z);
            /*This is Right side */
            stars(-20.0f, -15.0f, rand_1_Z);

#pragma endregion First_Bottom

        }

        if (flag_second)
        {

#pragma region Second_Top

            /*This is Left side */
            stars(20.0f, 20.0f, rand_2_Z);
            /*This is Left side */
            stars(20.0f, 15.0f, rand_2_Z);
            /*This is Left side */
            stars(10.0f, 10.0f, rand_2_Z);
            /*This is Center side */
            stars(0.0f, 20.0f, rand_2_Z);
            stars(0.0f, 5.0f, rand_2_Z);
            stars(0.0f, -20.0f, rand_2_Z);
            /*This is Right side */
            stars(-10.0f, 10.0f, rand_2_Z);
            /*This is Right side */
            stars(-20.0f, 15.0f, rand_2_Z);
            /*This is Right side */
            stars(-20.0f, 20.0f, rand_2_Z);

#pragma endregion Second_Top

#pragma region Second_Middle

            /*This is Left side */
           // stars(30.0f, 0.0f, rand_2_Z);
            /*This is Left side */
            stars(20.0f, 0.0f, rand_2_Z);
            /*This is Left side */
            stars(10.0f, 0.0f, rand_2_Z);
            /*This is Center side */
            stars(0.0f, 0.0f, rand_2_Z);
            /*This is Right side */
            stars(-10.0f, 0.0f, rand_2_Z);
            /*This is Right side */
            stars(-20.0f, 0.0f, rand_2_Z);
            /*This is Right side */
           // stars(-30.0f, 0.0f, rand_2_Z);

#pragma endregion Second_Middle

#pragma region Second_Bottom


        /*This is Left side */
            stars(20.0f, -15.0f, rand_2_Z);
            /*This is Left side */
            stars(10.0f, -10.0f, rand_2_Z);
            stars(0.0f, -5.0f, rand_2_Z);
            stars(0.0f, -20.0f, rand_2_Z);
            /*This is Right side */
            stars(-10.0f, -10.0f, rand_2_Z);
            /*This is Right side */
            stars(-20.0f, -15.0f, rand_2_Z);


#pragma endregion Second_Bottom
        }


        if (flag_third)
        {

#pragma region Third_Top

            /*This is Left side */
            stars(20.0f, 20.0f, rand_3_Z);
            /*This is Left side */
            stars(20.0f, 15.0f, rand_3_Z);
            /*This is Left side */
            stars(10.0f, 10.0f, rand_3_Z);
            /*This is Center side */
            stars(0.0f, 20.0f, rand_3_Z);
            stars(0.0f, 5.0f, rand_3_Z);
            stars(0.0f, -20.0f, rand_3_Z);
            /*This is Right side */
            stars(-10.0f, 10.0f, rand_3_Z);
            /*This is Right side */
            stars(-20.0f, 15.0f, rand_3_Z);
            /*This is Right side */
            stars(-20.0f, 20.0f, rand_3_Z);

#pragma endregion Third_Top

#pragma region Third_Middle

            /*This is Left side */
           // stars(30.0f, 0.0f, rand_3_Z);
            /*This is Left side */
            stars(20.0f, 0.0f, rand_3_Z);
            /*This is Left side */
            stars(10.0f, 0.0f, rand_3_Z);
            /*This is Center side */
            stars(0.0f, 0.0f, rand_3_Z);
            /*This is Right side */
            stars(-10.0f, 0.0f, rand_3_Z);
            /*This is Right side */
            stars(-20.0f, 0.0f, rand_3_Z);
            /*This is Right side */
           // stars(-30.0f, 0.0f, rand_3_Z);

#pragma endregion Third_Middle

#pragma region Third_Bottom

        /*This is Left side */
            stars(20.0f, -20.0f, rand_3_Z);
            /*This is Left side */
            stars(20.0f, -15.0f, rand_3_Z);
            /*This is Left side */
            stars(10.0f, -10.0f, rand_3_Z);
            /*This is Center side */
            stars(0.0f, -5.0f, rand_2_Z);
            stars(0.0f, -20.0f, rand_2_Z);
            /*This is Right side */
            stars(-10.0f, -10.0f, rand_3_Z);
            /*This is Right side */
            stars(-20.0f, -15.0f, rand_3_Z);
            /*This is Right side */
            stars(-20.0f, -20.0f, rand_3_Z);

#pragma endregion Third_Bottom
        }


        if (forword)
        {
            glColor3f(0.0f, 0.0f, 0.0f);    
            glTranslatef(0.0f, 0.0f, Sphere_Z);
            quadric = gluNewQuadric();
            gluSphere(quadric, 0.5f, 10, 10);
        }

        glPopMatrix();

    }
    else if (scene_2)
    {
    glPushMatrix();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        if (SUN)
        {
            glPushMatrix();

            glDisable(GL_LIGHTING);
            
            scane_2_sun();

            glPopMatrix();

        }
        
        gluLookAt(0.0f, 0.0f, -5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        glColor3f(1.0f, 1.0f, 1.0f);
        if (MERCURY)
        {
            scane_2_Mercury();
        }
        if (VENUS)
        {
            scane_2_Venus();
        }
        if (EARTH)
        {
            scane_2_Earth();
        }
        if (MARS)
        {
            scane_2_Mars();
        }
        if (JUPITOR)
        {
            scane_2_Jupitor();
        }
        if (SATURN)
        {
            scane_2_Saturn();
        }
        if (URANUS)
        {
            scane_2_Uranus();
        }
        if (NEPTUNE)
        {
            scane_2_Neptune();
        }
        if (PLUTO)
        {
            scane_2_Pluto();
        }

        glPopMatrix();
    }
    else if (scene_3)
    {
        glPushMatrix();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glPushMatrix();

        glDisable(GL_LIGHTING);

        sun();

        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(0.0f, 4.0f, -z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        glColor3f(1.0f, 1.0f, 1.0f);

        glLineWidth(0.1f);

        Mercury();
        Venus();
        Earth();
        Mars();
        Jupiter();
        Saturn();
        Uranus();
        Neptune();
        Pluto();

        glPopMatrix();

    }
    else if (scene_4)
    {
    
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0.0f, Scene_4_Y, 0.0f);

        glEnable(GL_LIGHT3);
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        glPushMatrix();

        if (Print_A)
        {
            glTranslatef(-3.5f, 1.0f, -5.0f);
            Print_Font_scene_4("A");
        }
        if (Print_S)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("S");
        }
        if (Print_T)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("T");
        }
        if (Print_R)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("R");
        }
        if (Print_O)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("O");
        }

        glPopMatrix();

        glPushMatrix();

        if (Print_M)
        {
            glTranslatef(-2.5f, -0.25f, -5.0f);
            Print_Font_scene_4("M");
        }
        if (Print_E)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("E");
        }
        if (Print_D)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("D");
        }
        if (Print_I)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("I");
        }

        glPopMatrix();

        glPushMatrix();

        if (Print_C)
        {
            glTranslatef(-2.5f, -1.5f, -5.0f);
            Print_Font_scene_4("C");
        }
        if (Print_C_O)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("O");
        }
        if (Print_C_M)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("M");
        }
        if (Print_P)
        {
            glTranslatef(1.0f, 0.0f, 0.0f);
            Print_Font_scene_4("P");
            Translate_scene_4 = true;
        }
        
        if (Print_P && Translate_scene_4)
        {
            glDisable(GL_LIGHTING);

            glTranslatef(-4.0f, -0.5f, 0.0f);
            glLineWidth(2.0f);
            glColor3f(1.0f, 1.0f, 1.0f);

            glBegin(GL_LINES);

            glVertex3f(-2.0f, 0.0f, 0.0f);
            glVertex3f(4.0f, 0.0f, 0.0f);

            glEnd();
            /*Was working well*/
           
            glTranslatef(0.0f, -4.5f, 0.0f);
            glBindTexture(GL_TEXTURE_2D, Master_DM);

            glEnable(GL_TEXTURE_2D);

            glBegin(GL_QUADS);

            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-2.6f, 4.0f, 0.0f);

            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-2.6f, 0.0f, 0.0f);

            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(4.5f, 0.0f, 0.0f);

            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(4.5f, 4.0f, 0.0f);

            glEnd();
            
            glDisable(GL_TEXTURE_2D);

            glBegin(GL_LINES);

            glVertex3f(-2.6f, 4.0f, 0.0f);
            glVertex3f(-2.6f, 0.0f, 0.0f);

            glVertex3f(-2.6f, 0.0f, 0.0f);
            glVertex3f(4.5f, 0.0f, 0.0f);

            glVertex3f(4.5f, 0.0f, 0.0f);
            glVertex3f(4.5f, 4.0f, 0.0f);

            glVertex3f(4.5f, 4.0f, 0.0f);
            glVertex3f(-2.6f, 4.0f, 0.0f);

            glEnd();

            glTranslatef(0.0f, -0.5f, 0.0f);

            glBegin(GL_LINES);

            glVertex3f(-2.0f, 0.0f, 0.0f);
            glVertex3f(4.0f, 0.0f, 0.0f);

            glEnd();
            
            glScalef(0.5f, 0.5f, 0.5f);
            glPushMatrix();
            glTranslatef(-4.0f, -1.5f, 0.0f);
            Print_Font("Sound Track : The Game Is Afoot.");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-4.0f, -3.0f, 0.0f);
            Print_Font("Group : Blend Group.");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-4.0f, -4.5f, 0.0f);
            Print_Font("Group Leader : Aditya Boob.");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-4.0f, -6.0f, 0.0f);
            Print_Font("Technology : OpenGL.");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-4.0f, -7.5f, 0.0f);
            Print_Font("Language : C.");
            glPopMatrix();
        }

        glPopMatrix();
    }
    else if (scene_5)
    {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -2.0f);

    glScalef(0.5f, 0.5f, 0.5f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();

    glTranslatef(-2.5f, 1.0f, -2.0f);
    Print_Font("Special Thanks !");

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-3.5f, -1.0f, -2.0f);
    Print_Font("Dr. Vijay Gokhale Sir.");

    glPopMatrix();
    }
    update();

    SwapBuffers(ghdc_DM);

}

void update(void)
{
    if (start)
    {
        if (fColor_x_DM < 0.5f && fColor_y_DM < 0.5f && fColor_z_DM < 0.5f)
        {
            fColor_x_DM += 0.00025f;
            fColor_y_DM += 0.00025f;
            fColor_z_DM += 0.00025f;
        }
        else
        {
            start = false;
            scene_1 = true;
        }
    }
    else if (scene_1)
    {

        if (flag_first)
        {
            if (!forword)
            {
                rand_1_Z += Incre_1;
                if (rand_1_Z > 5.0f)
                {
                    flag_second = true;
                }
                if (rand_1_Z > 80.0f)
                {
                    rand_1_Z = -30.0f;
                    if (Incre_1 < 0.2f && flag_first)
                    {
                        Incre_1 += 0.01f;
                    }
                }
            }
            else
            {
                rand_1_Z -= Incre_1;
                if (rand_1_Z < -40.0f)
                {
                    rand_1_Z = 80.0f;
                }
            }
        }
        if (flag_second)
        {
            if (!forword)
            {
                rand_2_Z += Incre_2;
                if (rand_2_Z > 5.0f)
                {
                    flag_third = true;

                }

                if (rand_2_Z > 80.0f)
                {

                    rand_2_Z = -30.0f;
                    if (Incre_2 < 0.2f && flag_second)
                    {
                        Incre_2 += 0.01f;
                    }
                }
            }
            else
            {
                rand_2_Z -= Incre_2;
                if (rand_2_Z < -40.0f)
                {
                    rand_2_Z = 80.0f;
                }

            }
        }
        if (flag_third)
        {
            if (!forword)
            {
                rand_3_Z += Incre_3;
                if (rand_3_Z > 70.0f)
                {
                    forword = true;
                }
                if (rand_3_Z > 80.0f)
                {

                    rand_3_Z = -30.0f;
                    if (Incre_3 < 0.2f && flag_third)
                    {
                        Incre_3 += 0.01f;
                    }
                }
            }
            else
            {
                rand_3_Z -= Incre_3;
                if (rand_3_Z < -40.0f)
                {
                    rand_3_Z = 80.0f;
                }
            }
        }
        if (forword)
        {
            Sphere_Z -= 0.05f;
            if (Sphere_Z < -20.0f)
            {
                forword = false;
                scene_1 = false;
                scene_2 = true;
                glEnable(GL_LIGHT2);
                SetTimer(ghwnd_DM, MYTIMER, 3100, NULL);
            }
        }


        scane_2_angle_DM += 0.18f;
        if (scane_2_angle_DM > 360.0f)
        {
            scane_2_angle_DM = 0.0f;
        }
    }
    else if (scene_2)
    {
        scane_2_angle_DM -= 0.1f;
        if (scane_2_angle_DM < 0.0f)
        {
            scane_2_angle_DM = 360.0f;
        }

        radial_scane_2_angle_DM -= 0.1f;
        if (radial_scane_2_angle_DM < 0.0f)
        {
            radial_scane_2_angle_DM = 360.0f;
        }
        Mercury_scane_2_angle_DM -= 0.22f;
        if (Mercury_scane_2_angle_DM < 0.0f)
        {
            Mercury_scane_2_angle_DM = 360.0f;
        }

        Venus_scane_2_angle_DM -= 0.26f;
        if (Venus_scane_2_angle_DM < 0.0f)
        {
            Venus_scane_2_angle_DM = 360.0f;
        }
        scane_2_Earth_angle -= 0.15f;
        if (scane_2_Earth_angle < 0.0f)
        {
            scane_2_Earth_angle = 360.0f;
        }
        
        Moon_scane_2_angle_DM -= 0.08f;
        if (Moon_scane_2_angle_DM < 0.0f)
        {
            Moon_scane_2_angle_DM = 360.0f;
        }
        scane_2_Moon_angle -= 0.1f;
        if (scane_2_Moon_angle < 0.0f)
        {
            scane_2_Moon_angle = 360.0f;
        }
        Earth_scane_2_angle_DM -= 0.2f;
        if (Earth_scane_2_angle_DM < 0.0f)
        {
            Earth_scane_2_angle_DM = 360.0f;
        }

        Mars_scane_2_angle_DM -= 0.15f;
        if (Mars_scane_2_angle_DM < 0.0f)
        {
            Mars_scane_2_angle_DM = 360.0f;
        }

        Jupitor_scane_2_angle_DM -= 0.15f;
        if (Jupitor_scane_2_angle_DM < 0.0f)
        {
            Jupitor_scane_2_angle_DM = 360.0f;
        }

        Saturn_scane_2_angle_DM -= 0.15f;
        if (Saturn_scane_2_angle_DM < 0.0f)
        {
            Saturn_scane_2_angle_DM = 360.0f;
        }

        Uranus_scane_2_angle_DM -= 0.15f;
        if (Uranus_scane_2_angle_DM < 0.0f)
        {
            Uranus_scane_2_angle_DM = 360.0f;
        }

        Neptune_scane_2_angle_DM -= 0.12f;
        if (Neptune_scane_2_angle_DM < 0.0f)
        {
            Neptune_scane_2_angle_DM = 360.0f;
        }

        Pluto_scane_2_angle_DM -= 0.1f;
        if (Pluto_scane_2_angle_DM < 0.0f)
        {
            Pluto_scane_2_angle_DM = 360.0f;
        }
    }
    else if (scene_3)
    {
        glLightfv(GL_LIGHT1, GL_POSITION, lPosition);
        glEnable(GL_LIGHT1);

        if (Camera_position_Forword)
        {
            z += 0.01955f;
            if (z > 45.0f)
            {
                Camera_position_Backword = true;
                Camera_position_Forword = false;
            }
        }
        if (Camera_position_Backword)
        {
            z -= 0.02f;
            if (z < 6.5f)
            {
                Camera_position_Backword = false;
                scene_3 = false;
                SetTimer(ghwnd_DM, MYAMCTIMER, 6000, NULL);
                scene_4 = true;
                glDisable(GL_LIGHT1);
                
            }
        }

        angle_DM -= 0.1f;
        if (angle_DM < 0.0f)
        {
            angle_DM = 360.0f;
        }

        radial_angle_DM -= 0.35f;
        if (radial_angle_DM < 0.0f)
        {
            radial_angle_DM = 360.0f;
        }

        Mercury_angle_DM -= 0.18f; // 0.22
        if (Mercury_angle_DM < 0.0f)
        {
            Mercury_angle_DM = 360.0f;
        }

        Venus_angle_DM -= 0.12f; //0.26
        if (Venus_angle_DM < 0.0f)
        {
            Venus_angle_DM = 360.0f;
        }

        Earth_angle_DM -= 0.16f; // 0.2
        if (Earth_angle_DM < 0.0f)
        {
            Earth_angle_DM = 360.0f;
        }

        Earth_angle -= 0.2f; // 0.5 
        if (Earth_angle < 0.0f)
        {
            Earth_angle = 360.0f;
        }

        Moon_angle_DM -= 0.08f; //0.08
        if (Moon_angle_DM < 0.0f)
        {
            Moon_angle_DM = 360.0f;
        }

        Moon_angle -= 0.1f;
        if (Moon_angle < 0.0f)
        {
            Moon_angle = 360.0f;
        }

        Mars_angle_DM -= 0.1f; //0.15 
        if (Mars_angle_DM < 0.0f)
        {
            Mars_angle_DM = 360.0f;
        }

        Jupitor_angle_DM -= 0.12f; //0.25
        if (Jupitor_angle_DM < 0.0f)
        {
            Jupitor_angle_DM = 360.0f;
        }

        Saturn_angle_DM -= 0.1f; // 0.15
        if (Saturn_angle_DM < 0.0f)
        {
            Saturn_angle_DM = 360.0f;
        }

        Uranus_angle_DM -= 0.15f; //0.22
        if (Uranus_angle_DM < 0.0f)
        {
            Uranus_angle_DM = 360.0f;
        }

        Neptune_angle_DM -= 0.08f;// 0.12
        if (Neptune_angle_DM < 0.0f)
        {
            Neptune_angle_DM = 360.0f;
        }

        Pluto_angle_DM -= 0.12f;// 0.3 
        if (Pluto_angle_DM < 0.0f)
        {
            Pluto_angle_DM = 360.0f;
        }
    }
    else if (scene_4)
    {
        if (Translate_scene_4)
        {
            if (Scene_4_Y < 4.495055)
            {
                Scene_4_Y += 0.005f;
            }
            if (Scene_4_Y > 4.45f && Move_Again)
            {
                Scene_4_Y += 0.005f;
            }
            if (Scene_4_Y > 16.0f)
            {
                scene_4 = false;
                Translate_scene_4 = false;
                scene_5 = true;
            }
            Inc += 0.005f;
            if (Inc > 6.0f)
            {
                Move_Again = true;
            }
        }
    }
    

}

void sun(void)
{
    glTranslatef(0.0f, 0.0f, -z);
    RenderToTexture(ROTATION_FROM_RADIAL);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, winWidth, winHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(44.0f, (GLfloat)winWidth / (GLfloat)winHeight, 0.1f, 100.0f);

    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -z);

    Drow_Model(ROTATION_FROM_SUN);

    scane_2_Radial_Effect(20, val);

    glPopMatrix();

}
void Mercury(void)
{
    glPushMatrix();

    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.1f)
    {
        glVertex3f(cosf(i) * 18.0f, 0.0f, sinf(i) * 18.0f);
    }

    glEnd();

    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Mercury_Texture_DM);


    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Mercury_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -18.0f, 0.0f);

    glRotatef(Mercury_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 2.0f, 30, 30);

    glPopMatrix();
}
void Venus(void) {

    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(0.1f);

    glDisable(GL_LIGHTING);

    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.05f)
    {
        glVertex3f(cosf(i) * 26.0f, 0.0f, sinf(i) * 26.0f);
    }

    glEnd();

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Venus_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -26.0f, 0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Venus_Texture_DM);
    glRotatef(Venus_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 2.5f, 30, 30);

    glPopMatrix();

}
void Earth(void) {
    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(0.1f);

    glDisable(GL_LIGHTING);
    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.05f)
    {
        glVertex3f(cosf(i) * 30.0f, 0.0f, sinf(i) * 30.0f);
    }

    glEnd();

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Earth_angle_DM, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
    
    glTranslatef(0.0f, -30.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, Earth_Texture_DM);


    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 3.0f, 40, 40);

    glRotatef(Earth_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 5.0f, 0.0f);
    glRotatef(Moon_angle_DM, 0.0f, 0.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, Moon_Texture_DM);
    glRotatef(Moon_angle, 0.0f, 0.0f, 1.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 1.0f, 40, 40);

    glPopMatrix();

    glPopMatrix();

}
void Mars(void) {

    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(0.1f);

    glDisable(GL_LIGHTING);

    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.05f)
    {
        glVertex3f(cosf(i) * 35.0f, 0.0f, sinf(i) * 35.0f);
    }

    glEnd();

    glEnable(GL_LIGHTING);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Mars_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -35.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Mars_Texture_DM);
    glRotatef(Mars_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 2.25f, 30, 30);

    glPopMatrix();

}
void Jupiter(void) {

    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(0.1f);

    glDisable(GL_LIGHTING);

    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.05f)
    {
        glVertex3f(cosf(i) * 40.0f, 0.0f, sinf(i) * 40.0f);
    }

    glEnd();

    glEnable(GL_LIGHTING);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Jupitor_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -40.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Jupiter_Texture_DM);
    glRotatef(Jupitor_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 4.0f, 30, 30);

    glPopMatrix();
}
void Saturn(void) {
    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(0.1f);

    glDisable(GL_LIGHTING);

    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.05f)
    {
        glVertex3f(cosf(i) * 45.0f, 0.0f, sinf(i) * 45.0f);
    }

    glEnd();

    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Saturn_Texture_DM);


    glPushMatrix();

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Saturn_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -45.0f, 0.0f);

    glRotatef(Saturn_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 3.5f, 30, 30);


    glPopMatrix();
    glDisable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D, Saturn_Ring_Texture_DM);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Saturn_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -45.0f, 0.0f);
    glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluDisk(quadric, 3.5f, 6.0f, 25, 50);

    glPopMatrix();
    glEnable(GL_LIGHTING);
}
void Uranus(void) {

    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(0.1f);

    glDisable(GL_LIGHTING);

    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.05f)
    {
        glVertex3f(cosf(i) * 50.0f, 0.0f, sinf(i) * 50.0f);
    }

    glEnd();

    glEnable(GL_LIGHTING);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Uranus_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -50.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Uranus_Texture_DM);
    glRotatef(Uranus_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 3.75f, 30, 30);

    glPopMatrix();

}
void Neptune(void) {

    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(0.1f);

    glDisable(GL_LIGHTING);

    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.05f)
    {
        glVertex3f(cosf(i) * 55.0f, 0.0f, sinf(i) * 55.0f);
    }

    glEnd();

    glEnable(GL_LIGHTING);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Neptune_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -55.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Neptune_Texture_DM);
    glRotatef(Neptune_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 3.25f, 30, 30);

    glPopMatrix();
}
void Pluto(void) {

    glPushMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(0.1f);

    glDisable(GL_LIGHTING);

    glBegin(GL_LINE_LOOP);

    for (GLfloat i = 0; i < (M_PI * 2); i += 0.05f)
    {
        glVertex3f(cosf(i) * 60.0f, 0.0f, sinf(i) * 60.0f);
    }

    glEnd();

    glEnable(GL_LIGHTING);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Pluto_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -60.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Pluto_Texture_DM);
    glRotatef(Pluto_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 2.0f, 30, 30);

    glPopMatrix();
}

void scane_2_sun(void)
{
    glTranslatef(0.0f, 0.0f, -20.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    scane_2_RenderToTexture(ROTATION_FROM_RADIAL);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, winWidth, winHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(44.0f, (GLfloat)winWidth / (GLfloat)winHeight, 0.1f, 100.0f);

    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -20.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    scane_2_Drow_Model(ROTATION_FROM_SUN);

    scane_2_Radial_Effect(20, 0.01f);

    glPopMatrix();

}
void scane_2_Mercury(void)
{
    glPushMatrix();

    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Mercury_Texture_DM);

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Mercury_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 2.0f, 40, 40);

    glPopMatrix();
}
void scane_2_Venus(void) {

    glPushMatrix();

    glTranslatef(0.0f, -0.0f, 2.0f);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Venus_Texture_DM);
    
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Venus_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 2.5f, 40, 40);

    glPopMatrix();

}
void scane_2_Earth(void) {

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 6.0f);

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    
    
    glPushMatrix();
    glRotatef(scane_2_Earth_angle, 0.0f, 0.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, Earth_Texture_DM);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 4.0f, 40, 40);
    
    glPopMatrix();

    glPushMatrix();
    glRotatef(Moon_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 8.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, Moon_Texture_DM);
    glRotatef(scane_2_Moon_angle, 0.0f, 0.0f, 1.0f);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 1.5f, 40, 40);

    glPopMatrix();

    glPopMatrix();

}
void scane_2_Mars(void) {

    glPushMatrix();

    glTranslatef(0.0f, -0.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Mars_Texture_DM);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Mars_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 2.25f, 40, 40);

    glPopMatrix();

}
void scane_2_Jupitor(void) {

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 5.0f);
    
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Jupiter_Texture_DM);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Jupitor_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 4.0f, 40, 40);

    glPopMatrix();
}
void scane_2_Saturn(void) {

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 7.0f);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Saturn_Texture_DM);

    glPushMatrix();

    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Saturn_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 3.5f, 40, 40);
        
    glPopMatrix();
    glDisable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D, Saturn_Ring_Texture_DM);

    glRotatef(80.0f, 1.0f, 1.0f, 0.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluDisk(quadric, 4.0f, 6.0f, 50, 50);

    glPopMatrix();
    glEnable(GL_LIGHTING);

}
void scane_2_Uranus(void) {

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 5.0f);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Uranus_Texture_DM);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Uranus_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 3.75f, 40, 40);

    glPopMatrix();

}
void scane_2_Neptune(void) {

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 4.0f);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Neptune_Texture_DM);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Neptune_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 3.25f, 40, 40);

    glPopMatrix();
}
void scane_2_Pluto(void) {

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Pluto_Texture_DM);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(Pluto_scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 2.0f, 30, 30);

    glPopMatrix();
}

void scane_2_Radial_Effect(int times, float inc)
{

    float spost = 0.0f;                               // Starting Texture Coordinate Offset
    float alphainc = 0.05f / times;                  // Fade Speed For Alpha Blending
    float alpha = 0.18f;                             // Starting Alpha Value
    float x_drece = 0.0f;

    glEnable(GL_TEXTURE_2D);                             // Enable 2D Texture Mapping
    glDisable(GL_DEPTH_TEST);                           // Disable Depth Testing
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);                  // Set Blending Mode
    glEnable(GL_BLEND);                                 // Enable Blending
    glBindTexture(GL_TEXTURE_2D, Texture_ID);           // Bind To The Blur Texture

    ViewOrtho();                                    // Switch To An Ortho View

    x_drece = inc;
    alphainc = alpha / times;                       // alphainc=0.2f / Times To Render Blur

    glBegin(GL_QUADS);                              // Begin Drawing Quads
    for (int num = 0; num < times; num++)          // Number Of Times To Render Blur
    {
        glColor4f(0.5f, 0.25f, 0.1f, alpha);
        glTexCoord2f(0 + spost, 1 - spost);
        glVertex2f(0, 0);

        glTexCoord2f(0 + spost, 0 + spost);
        glVertex2f(0, 480);

        glTexCoord2f(1 - spost, 0 + spost);
        glVertex2f(640, 480);

        glTexCoord2f(1 - spost, 1 - spost);
        glVertex2f(640, 0);

        spost += inc;                       // Gradually Increase spost (Zooming Closer To Texture Center)
        alpha = alpha - alphainc;           // Gradually Decrease alpha (Gradually Fading Image Out)
    }
    glEnd();

    ViewPerspective();                      // Switch To A Perspective View

    glEnable(GL_DEPTH_TEST);                    // Enable Depth Testing
    glDisable(GL_TEXTURE_2D);                   // Disable 2D Texture Mapping
    glDisable(GL_BLEND);                        // Disable Blending
    glBindTexture(GL_TEXTURE_2D, 0);                 // Unbind The Blur Texture

}

void ViewOrtho()                            // Set Up An Ortho View
{
    glMatrixMode(GL_PROJECTION);                    // Select Projection
    glPushMatrix();                         // Push The Matrix
    glLoadIdentity();                       // Reset The Matrix
    glOrtho(0, 640, 480, 0, -1, 1);             // Select Ortho Mode (640x480)
    glMatrixMode(GL_MODELVIEW);                 // Select Modelview Matrix
    glPushMatrix();                         // Push The Matrix
    glLoadIdentity();                       // Reset The Matrix

}

void ViewPerspective()                          // Set Up A Perspective View
{
    glMatrixMode(GL_PROJECTION);                  // Select Projection
    glPopMatrix();                          // Pop The Matrix
    glMatrixMode(GL_MODELVIEW);                   // Select Modelview
    glPopMatrix();                          // Pop The Matrix
}

void scane_2_Drow_Model(int flag)
{
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Sun_Texture_DM);

    scane_2_Sun_rotation(flag);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 6.0f, 40, 40);

    glPopMatrix();
}

void Drow_Model(int flag)
{
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindTexture(GL_TEXTURE_2D, Sun_Texture_DM);

    Sun_rotation(flag);

    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    gluSphere(quadric, 6.0f, 30, 30);

    glPopMatrix();
}

void scane_2_RenderToTexture(int flag)
{
    glPushMatrix();

    glViewport(0, 0, 640.0f, 480.0f);

    scane_2_Drow_Model(flag);

    glBindTexture(GL_TEXTURE_2D, Texture_ID);
    glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 0, 0, 640, 480, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

}

void RenderToTexture(int flag)
{
    glPushMatrix();

    glViewport(0, 0, 400.0f, 400.0f);

    Drow_Model(flag);

    glBindTexture(GL_TEXTURE_2D, Texture_ID);
    glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 0, 0, 400, 400, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

}

void scane_2_Sun_rotation(int flag)
{
    switch (flag)
    {
    case ROTATION_FROM_SUN:
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
        break;
    case ROTATION_FROM_RADIAL:
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(radial_scane_2_angle_DM, 1.0f, 1.0f, 1.0f);
        break;

    }


}

void Sun_rotation(int flag)
{
    switch (flag)
    {
    case ROTATION_FROM_SUN:
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(angle_DM, 0.0f, 0.0f, 1.0f);
        break;
    case ROTATION_FROM_RADIAL:
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(radial_angle_DM, 0.0f, 1.0f, 1.0f);
        break;
    }
}

void stars(GLfloat x, GLfloat y, GLfloat z)
{
    glLineWidth(2.0f);
    glPushMatrix();

    glRotatef(scane_2_angle_DM, 0.0f, 0.0f, 1.0f);
    glTranslatef(x, y, z);

    for (size_t i = 0; i < 20; i++)
    {

        glPushMatrix();

        glTranslatef(1.0f, 2.0f, 0.0f);

        if (i < 5)
        {
            glTranslatef((i + 2.5f) * sinf((GLfloat)(rand_val[i])), 1.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else if (i < 10 && i > 4)
        {
            glTranslatef((i + -4.5f) * sinf((GLfloat)(rand_val[i] / 10.0f)), 3.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else if (i < 15 && i > 9)
        {
            glTranslatef((i + -7.5f) * sinf((GLfloat)(rand_val[i] / 10.0f)), -2.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else
        {
            glTranslatef((i + 1.0f) * sinf((GLfloat)(rand_val[i] / 10.0f)), -4.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }

        glBegin(GL_LINES);

        if (!forword)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, -2.0f);
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, 2.0f);
        }
        else
        {
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, -2.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, 2.0f);
        }
        glEnd();

        glPopMatrix();


        glPushMatrix();

        glTranslatef(1.0f, -2.0f, 0.0f);

        if (i < 5)
        {
            glTranslatef((i + 2.5f) * sinf((GLfloat)(rand_val[i])), 1.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else if (i < 10 && i > 4)
        {
            glTranslatef((i + -4.5f) * sinf((GLfloat)(rand_val[i] / 10.0f)), 3.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else if (i < 15 && i > 9)
        {
            glTranslatef((i + -7.5f) * sinf((GLfloat)(rand_val[i] / 10.0f)), -2.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else
        {
            glTranslatef((i + 1.0f) * sinf((GLfloat)(rand_val[i] / 10.0f)), -4.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }

        glBegin(GL_LINES);

        if (!forword)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, -2.0f);
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, 2.0f);
        }
        else
        {
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, -2.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, 2.0f);
        }

        glEnd();


        glPopMatrix();

        glPushMatrix();

        glTranslatef(10.0f, 2.0f, 0.0f);

        if (i < 5)
        {
            glTranslatef((i + 2.5f) * sinf((GLfloat)(rand_val[i])), 1.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else if (i < 10 && i > 4)
        {
            glTranslatef((i + -4.5f) * sinf((GLfloat)(rand_val[i] / 10.0f)), 3.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else if (i < 15 && i > 9)
        {
            glTranslatef((i + -7.5f) * sinf((GLfloat)(rand_val[i] / 10.0f)), -2.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else
        {
            glTranslatef((i + 1.0f) * sinf((GLfloat)(rand_val[i] / 10.0f)), -4.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }

        glBegin(GL_LINES);

        if (!forword)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, -2.0f);
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, 2.0f);
        }
        else
        {
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, -2.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, 2.0f);
        }

        glEnd();


        glPopMatrix();

        glPushMatrix();

        glTranslatef(10.0f, -2.0f, 0.0f);

        if (i < 5)
        {
            glTranslatef((i + 2.5f) * sinf((GLfloat)(rand_val[i])), 1.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else if (i < 10 && i > 4)
        {
            glTranslatef((i + -4.5f) * sinf((GLfloat)(rand_val[i] / 10.0f)), 3.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else if (i < 15 && i > 9)
        {
            glTranslatef((i + -7.5f) * sinf((GLfloat)(rand_val[i] / 10.0f)), -2.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }
        else
        {
            glTranslatef((i + 1.0f) * sinf((GLfloat)(rand_val[i] / 10.0f)), -4.0f + cosf((GLfloat)(rand_val[i])), (i * 1.0f) * cosf((GLfloat)(rand_val[i])));
        }

        glBegin(GL_LINES);

        if (!forword)
        {
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, -2.0f);
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, 2.0f);
        }
        else
        {
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, -2.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f((GLfloat)rand_val[i], 0.0f, 2.0f);
        }

        glEnd();


        glPopMatrix();

    }
    glPopMatrix();
}

GLvoid BuildFont(GLvoid)                    // Build Our Bitmap Font
{
    HFONT   font;                           // Windows Font ID

    base = glGenLists(256);                 // Storage For 256 Characters
    font = CreateFont(-12,                  // Height Of Font
        0,                                  // Width Of Font
        0,                                  // Angle Of Escapement
        0,                                  // Orientation Angle
        100,                                // Font Weight
        FALSE,                              // Italic
        FALSE,                              // Underline
        FALSE,                              // Strikeout
        ANSI_CHARSET,                       // Character Set Identifier
        OUT_TT_PRECIS,                      // Output Precision
        CLIP_DEFAULT_PRECIS,                // Clipping Precision
        ANTIALIASED_QUALITY,                // Output Quality
        FF_DONTCARE | DEFAULT_PITCH,        // Family And Pitch
        TEXT("Palatino Linotype"));         // Font Name

    SelectObject(ghdc_DM, font);            // Selects The Font We Created

    wglUseFontOutlines(ghdc_DM,             // Select The Current DC
        0,                                  // Starting Character
        255,                                // Number Of Display Lists To Build
        base,                               // Starting Display Lists
        0.0f,                               // Deviation From The True Outlines
        0.001f,                              // Font Thickness In The Z Direction
        WGL_FONT_POLYGONS,                  // Use Polygons, Not Lines
        gmf);                               // Address Of Buffer To Recieve Data
}

GLvoid Print_Font(const char* fmt, ...)     // Custom GL "Print" Routine
{
    char* text;                             // Holds Our String

    if (fmt == NULL)                        // If There's No Text
        return;

    // Do Nothing
    text = (char*)fmt;

    glPushAttrib(GL_LIST_BIT);                          // Pushes The Display List Bits
    glListBase(base);                                   // Sets The Base Character to 0
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);  // Draws The Display List Text
    glPopAttrib();                                      // Pops The Display List Bits
}

GLvoid KillFont(GLvoid)
{
    glDeleteLists(base, 256);
}

GLvoid BuildFont_scene_4(GLvoid)                    // Build Our Bitmap Font
{
    HFONT   font;                           // Windows Font ID

    base_scene_4 = glGenLists(256);                 // Storage For 256 Characters
    font = CreateFont(-12,                  // Height Of Font
        0,                                  // Width Of Font
        0,                                  // Angle Of Escapement
        0,                                  // Orientation Angle
        100,                                // Font Weight
        FALSE,                              // Italic
        FALSE,                              // Underline
        FALSE,                              // Strikeout
        ANSI_CHARSET,                       // Character Set Identifier
        OUT_TT_PRECIS,                      // Output Precision
        CLIP_DEFAULT_PRECIS,                // Clipping Precision
        ANTIALIASED_QUALITY,                // Output Quality
        FF_DONTCARE | DEFAULT_PITCH,        // Family And Pitch
        TEXT("Times New Roman"));         // Font Name

    SelectObject(ghdc_DM, font);            // Selects The Font We Created

    wglUseFontOutlines(ghdc_DM,             // Select The Current DC
        0,                                  // Starting Character
        255,                                // Number Of Display Lists To Build
        base_scene_4,                               // Starting Display Lists
        0.0f,                               // Deviation From The True Outlines
        0.25f,                              // Font Thickness In The Z Direction
        WGL_FONT_POLYGONS,                  // Use Polygons, Not Lines
        gmf_scene_4);                               // Address Of Buffer To Recieve Data
}

GLvoid Print_Font_scene_4(const char* fmt, ...)     // Custom GL "Print" Routine
{
    char* text;                             // Holds Our String

    if (fmt == NULL)                        // If There's No Text
        return;

    // Do Nothing
    text = (char*)fmt;

    glPushAttrib(GL_LIST_BIT);                          // Pushes The Display List Bits
    glListBase(base_scene_4);                                   // Sets The Base Character to 0
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);  // Draws The Display List Text
    glPopAttrib();                                      // Pops The Display List Bits
}

GLvoid KillFont_scene_4(GLvoid)
{
    glDeleteLists(base_scene_4, 256);
}

void unInitialize()
{
    //code
    if (gdFullScreen_DM == TRUE)
    {
        dwStyle_D = GetWindowLong(ghwnd_DM, GWL_STYLE);
        SetWindowLong(ghwnd_DM, GWL_STYLE, (dwStyle_D | WS_OVERLAPPEDWINDOW));
        SetWindowPlacement(ghwnd_DM, &wpPrev_DM);
        SetWindowPos(ghwnd_DM, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
        ShowCursor(TRUE);
    }

    if (quadric)
    {
        gluDeleteQuadric(quadric);
        quadric = NULL;
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


    if (gpFile_DM)
    {
        fclose(gpFile_DM);
        gpFile_DM = NULL;
    }
    KillFont();
}


