#include<windows.h>
#include"Header.h"
#include<gl/GL.h>
#include<stdio.h>
#include<gl/GLU.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>

#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib,"Glu32.lib")

#define WIN_WIDTH_DM 800
#define WIN_HEIGHT_DM 600

#define IMG_WIDTH_DM 128
#define IMG_HEIGHT_DM 128


//Global Fuction 
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Frame Buffer Variables
GLuint Texture_ID;

GLfloat rotate_cube_DM = 0.0f;
GLfloat val = 0.0f;



//Frame Buffer Fuction 
void CreateTexture(GLuint*);
void RenderToTexture(void); 
void Drow_Model(void);
void ViewOrtho(void);
void ViewPerspective(void);
void Radial_Effect(int times, float inc);


// Global Variables Declaration 
DWORD dwStyle_D;
WINDOWPLACEMENT wpPrev_DM = { sizeof(WINDOWPLACEMENT) };
bool gdFullScreen_DM = false;
HWND ghwnd_DM = NULL;
bool gbActiveWindows_DM = false;
HDC ghdc_DM = NULL;
HGLRC ghrc_DM = NULL;
FILE* gpFile_DM = NULL;
GLfloat angle_DM = 0.0f;

GLuint winWidth = 0;
GLuint winHeight = 0;
//Local Function 
void Resize(int, int);
void unInitialize(void);
void Display(void);
void update(void);



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreIntance, LPSTR lpszCmdLine, int iCmdShow)
{
    //Function 

    void Initialize(void);

    WNDCLASSEX wndclassex;
    HWND hwnd;
    MSG msg;
    TCHAR Appname[] = TEXT("MY_SAMPLE");
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
        TEXT("MY Radial Blur...!"),
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
              
                Display();
            }
        }

    }

    return(msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    //Function
    void ToggelFullScreen(void);


    switch (iMsg)
    {
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
        	val += 0.005f; 
        	break;
        	case VK_DOWN:
        	val -= 0.005f; 
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

void ToggelFullScreen()
{
    //Local Variable Declare
    MONITORINFO mi_D = { sizeof(MONITORINFO) };

    //Code
    if (gdFullScreen_DM == false)
    {
        dwStyle_D = GetWindowLong(ghwnd_DM, GWL_STYLE);
        if (dwStyle_D & WS_OVERLAPPEDWINDOW)
        {
            if (GetWindowPlacement(ghwnd_DM, &wpPrev_DM) && GetMonitorInfo(MonitorFromWindow(ghwnd_DM, MONITORINFOF_PRIMARY), &mi_D))
            {
                SetWindowLong(ghwnd_DM, GWL_STYLE, (dwStyle_D & ~WS_OVERLAPPEDWINDOW));
                SetWindowPos(ghwnd_DM, HWND_TOP, mi_D.rcMonitor.left, mi_D.rcMonitor.top, mi_D.rcMonitor.right - mi_D.rcMonitor.left, mi_D.rcMonitor.bottom - mi_D.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED); // SWP_FRAMECHANGED = WM_NCCALCSIZE      
            }

        }
        ShowCursor(FALSE);
        gdFullScreen_DM = true;
    }
    else
    {
        SetWindowLong(ghwnd_DM, GWL_STYLE, (dwStyle_D | WS_OVERLAPPEDWINDOW));
        SetWindowPlacement(ghwnd_DM, &wpPrev_DM);
        SetWindowPos(ghwnd_DM, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
        ShowCursor(TRUE);
        gdFullScreen_DM = false;
    }

}

void Initialize()
{
    PIXELFORMATDESCRIPTOR pfd_DM;
    int iPixelFormatIndex_DM;

    ghdc_DM = GetDC(ghwnd_DM);

    ZeroMemory(&pfd_DM, sizeof(PIXELFORMATDESCRIPTOR));

    pfd_DM.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd_DM.nVersion = 1;
    pfd_DM.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd_DM.iPixelType = PFD_TYPE_RGBA;
    pfd_DM.cColorBits = 32;
    //Depth
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

    //for getting anti_Allies
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//Preventing From Perspective Destortion

    // Call for creating the texture
    CreateTexture(&Texture_ID);
    if(Texture_ID == NULL)
    {
    	fprintf_s(gpFile_DM,"\n  Unable to create Texture....!!!\n");
    	exit(1);
    }


    Resize(WIN_WIDTH_DM, WIN_HEIGHT_DM);

}

void CreateTexture( GLuint *Texture_n)
{
	GLuint *data;

	data = (GLuint *)malloc((IMG_HEIGHT_DM * IMG_WIDTH_DM) * 4 * sizeof(GLuint));
	if(data == NULL)
	{
		fprintf_s(gpFile_DM,"Unable to Allocated Memeory...!!!\n");
		exit(1);
	}
	ZeroMemory(data, ((IMG_WIDTH_DM * IMG_HEIGHT_DM) * 4 * sizeof(GLuint)));

	glGenTextures(1, Texture_n);
	glBindTexture(GL_TEXTURE_2D, *Texture_n);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, 128, 128, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, data);           // Build Texture Using Information In data

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    free(data);

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
    // for Depth Add GL_DEPTH_BUFFER_BIT 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0f, 0.0f, -50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	RenderToTexture();
  	Drow_Model();
  	Radial_Effect(20, val);    

    update();

    SwapBuffers(ghdc_DM);

}



void Radial_Effect(int times, float inc)
{

	float spost = 0.0f;                     // Starting Texture Coordinate Offset
    float alphainc = 0.9f / times;                  // Fade Speed For Alpha Blending
    float alpha = 0.1f;                     // Starting Alpha Value
 
    glEnable(GL_TEXTURE_2D);                    // Enable 2D Texture Mapping
    glDisable(GL_DEPTH_TEST);                   // Disable Depth Testing
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);               // Set Blending Mode
    glEnable(GL_BLEND);                     // Enable Blending
    glBindTexture(GL_TEXTURE_2D, Texture_ID);           // Bind To The Blur Texture
    ViewOrtho();                            // Switch To An Ortho View
 
    alphainc = alpha / times;                   // alphainc=0.2f / Times To Render Blur

    glBegin(GL_QUADS);                      // Begin Drawing Quads
        for (int num = 0;num < times;num++)          // Number Of Times To Render Blur
        {
            glColor4f(0.5f, 0.0f, 0.7f, alpha);     // Set The Alpha Value (Starts At 0.2)
            glTexCoord2f(0+spost,1-spost);          // Texture Coordinate   (   0,   1 )
            glVertex2f(0,0);                // First Vertex     (   0,   0 )
 
            glTexCoord2f(0+spost,0+spost);          // Texture Coordinate   (   0,   0 )
            glVertex2f(0,480);              // Second Vertex    (   0, 480 )
 
            glTexCoord2f(1-spost,0+spost);          // Texture Coordinate   (   1,   0 )
            glVertex2f(640,480);                // Third Vertex     ( 640, 480 )
 
            glTexCoord2f(1-spost,1-spost);          // Texture Coordinate   (   1,   1 )
            glVertex2f(640,0);              // Fourth Vertex    ( 640,   0 )
 
            spost += inc;                   // Gradually Increase spost (Zooming Closer To Texture Center)
            alpha = alpha - alphainc;           // Gradually Decrease alpha (Gradually Fading Image Out)
        }
    glEnd();                            // Done Drawing Quads
 
    ViewPerspective();                      // Switch To A Perspective View
 
    glEnable(GL_DEPTH_TEST);                    // Enable Depth Testing
    glDisable(GL_TEXTURE_2D);                   // Disable 2D Texture Mapping
    glDisable(GL_BLEND);                        // Disable Blending
    glBindTexture(GL_TEXTURE_2D,0);                 // Unbind The Blur Texture

}


void ViewOrtho()                            // Set Up An Ortho View
{
    glMatrixMode(GL_PROJECTION);                    // Select Projection
    glPushMatrix();                         // Push The Matrix
    glLoadIdentity();                       // Reset The Matrix
    glOrtho( 0, 640 , 480 , 0, -1, 1 );             // Select Ortho Mode (640x480)
    glMatrixMode(GL_MODELVIEW);                 // Select Modelview Matrix
    glPushMatrix();                         // Push The Matrix
    glLoadIdentity();                       // Reset The Matrix
}
 
void ViewPerspective()                          // Set Up A Perspective View
{
    glMatrixMode( GL_PROJECTION );                  // Select Projection
    glPopMatrix();                          // Pop The Matrix
    glMatrixMode( GL_MODELVIEW );                   // Select Modelview
    glPopMatrix();                          // Pop The Matrix
}

void Drow_Model(void)
{
    glPushMatrix();                        		// Push The Modelview Matrix

    glRotatef(rotate_cube_DM, 1.0f, 0.0f, 0.0f);
    glRotatef(rotate_cube_DM, 0.0f, 1.0f, 0.0f);
    glRotatef(rotate_cube_DM, 0.0f, 0.0f, 1.0f);

    glColor3f( 0.5f, 0.0f, 0.7f);
    glBegin(GL_QUADS); 					// Start Rendering Quads

    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);

    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);

    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);

    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, -5.0f);

    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);

    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(-0.5f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);


    glEnd();
     
    glPopMatrix();
}

void RenderToTexture(void)
{
	glViewport( 0, 0, 128.0f, 128.0f);

	Drow_Model();

	glBindTexture(GL_TEXTURE_2D, Texture_ID);
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 0, 0, 128, 128, 0);

	glClearColor(0.0f, 0.0f, 0.0f, 0.5);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glViewport(0, 0, winWidth, winHeight);

}

void update(void)
{
	rotate_cube_DM += 0.3f;
	if(rotate_cube_DM > 360.0f)
	{
		rotate_cube_DM = 0.0f;
	}
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

}

