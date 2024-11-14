#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::DatePicker::implementation
{
	int32_t MainWindow::MyProperty()
	{
		throw hresult_not_implemented();
	}

	void MainWindow::MyProperty(int32_t /* value */)
	{
		throw hresult_not_implemented();
	}

	void MainWindow::saveBtn_Click(IInspectable const& sender, RoutedEventArgs const& args)
	{
		Windows::Foundation::DateTime dateTime;
		dateTime = myDatePicker().Date(); // Get the selected date
		m_myDate = dateTime.time_since_epoch().count(); // Save the selected date
		myTextBox().Text(to_hstring(m_myDate)); // Display the selected date
	}

	void MainWindow::loadBtn_Click(IInspectable const& sender, RoutedEventArgs const& args)
	{
		// Load the selected date
		myDatePicker().SelectedDate(winrt::Windows::Foundation::DateTime{ winrt::Windows::Foundation::TimeSpan{m_myDate} });
	}
}
