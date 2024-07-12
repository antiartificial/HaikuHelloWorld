#include <Application.h>
#include <Window.h>
#include <View.h>
#include <StringView.h>

class HelloWorldWindow : public BWindow {
public:
	HelloWorldWindow() : BWindow(BRect(100, 100, 400, 200), "Hello World!", B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE) {
		BView* view = new BView(Bounds(), "view", B_FOLLOW_ALL, B_WILL_DRAW);
		view->SetViewColor(216, 216, 216);
		AddChild(view);
		
		BStringView* stringView = new BStringView(BRect(10, 10, 200, 30), "stringView", "Hello, World!");
		view->AddChild(stringView);
	}
};

class HelloWorldApp : public BApplication {
public: 
	HelloWorldApp() : BApplication("application/x-vnd.HelloWorld") {}
	void ReadyToRun() {
		BWindow* window = new HelloWorldWindow();
		window->Show();
	}
};

int main() {
	HelloWorldApp app;
	app.Run();
	return 0;
}
