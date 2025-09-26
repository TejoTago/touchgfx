# TouchGFX Dynamic Graphs Demo

This project demonstrates how to create two dynamic graphs with toggle buttons that control the visibility of graph elements (lines and dots) using TouchGFX Designer and STM32CubeIDE.

Random values between -20 and 100 are generated to simulate sensor readings. In a real-world scenario, these graphs could display live data from sensors such as temperature, pressure, or voltage.

---

## Step-by-Step Guide

### 1. Create a New Application
- Open **TouchGFX Designer**.
- Select your **target board**.
- Click **Create** to start a new project.

### 2. Add a Scalable Image
- Drag a **Scalable Image** widget onto the screen.
- Choose an image from your file system or use one from the GFX stock library.

### 3. Add Dynamic Graphs
- Add two **Dynamic Graph** widgets to the screen: `dynamicGraphBlue` and `dynamicGraphGreen`.

#### Configure Each Graph:
- **Graph Area Margins & Padding**: Adjust layout spacing.
- **Dynamic Behavior**: Set to `Scroll` to enable continuous X-axis updates as new data points are added.
- **Number of Data Points**: Defines how many points are visible on the X-axis at a time.
- **Value Range**: Set Y-axis range to `-20 to 100` (constant).
- **Elements**: Add both `Line` and `Dots` to visualize data.
- **Grid Lines**: Enable horizontal grid lines for better readability.
- **Axis Labels**: Add labels for both X and Y axes.

### 4. Add Toggle Buttons
- Add four **Toggle Buttons** to control visibility:
  - Blue Line
  - Blue Dots
  - Green Line
  - Green Dots
- Use stock images: `toggle_off` and `toggle_on`.

### 5. Add Interactions
- Create four **Interactions**, one for each toggle button.
- On button click, call a virtual function:
  - `updateBlueGraph()` for blue graph toggles.
  - `updateGreenGraph()` for green graph toggles.

### 6. Save and Generate Code
- Click **Save** and **Generate Code**.
- Open the generated project in STM32CubeIDE:
C:\TouchGFXProjects\Dynamic_random\STM32CubeIDE.cproject

Once in CubeIDE, you can implement the logic to:
- Generate random values.
- Update graphs periodically.
- Control visibility of graph elements based on toggle states.

# CODE

## DynamicGraphMenuView Constructor
Creates a new view instance, initializing tickCounter, lastBlueValue, and lastGreenValue to zero. It seeds the random number generator using tickCounter, which will be incremented over time. This setup enables later random value generation for graph simulation and ensures initial values are well-defined for UI logic.

## setupScreen
Prepares the screen by invoking the base class initialization and programmatically setting toggle buttons to “on” for blue and green lines and dots. The function then calls updateBlueGraph() and updateGreenGraph() to ensure that both graph elements reflect the initial toggle states. This guarantees UI consistency at startup and sets a predictable default visualization.

## tearDownScreen
Handles screen teardown by delegating to the base class’s teardown logic. This provides a placeholder for future extension if resource cleanup or specific de-initialization is required during navigation away from this screen. 

## handleTickEvent
Called on every UI tick, it increments the tick counter and, every tenth tick, generates new simulated data points for both blue and green graphs using generateDeltaValue(). These updates drive live dynamic graph animations and periodic data plotting, synchronizing visual updates with the UI event timeline.

## generateDeltaValue
Generates a random data value based on the last value, within a specified delta, then clamps it between the provided minimum and maximum. Updates the referenced lastValue for subsequent calls. This function enables smooth simulated data variation for demo or testing purposes, ensuring controlled jumps and preventing out-of-range errors.

## updateLineVisibility
Sets the visibility (alpha) of a provided line graph element based on the associated toggle button’s state, invalidating the line to trigger a redraw. This function modularizes the UI logic for showing or hiding line data, supporting interactive customization of the graph appearance.

## updateDotsVisibility
Similar to updateLineVisibility, but applies to dot elements. Changes dot transparency and requests a redraw in response to toggle state. This ensures dot visibility in the graph mimics user preferences or application mode.

## updateGraphElements
Synchronizes the visibility of both line and dot elements (and forces a graph refresh) based on the states of their corresponding toggles.

## updateBlueGraph
Calls updateGraphElements for the blue graph, updating line and dot appearance and then invalidating the entire blue graph container to force a complete redraw. This is triggered during startup, or whenever blue-related toggles change. 

updateGreenGraph
Analogous to updateBlueGraph, but for the green data series.
