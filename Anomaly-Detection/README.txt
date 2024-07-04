Anomaly Detection

ML Algorithms that we tried: 
     1. Z-score & IsolationForest
     2. Multi-Level Perceptron (MLP)
     3. LSTM


Generate Initial Dataset:

Create a new column with 20 unique values.
Use fixed x values [0.65, 0.70, 0.75, 0.80, 0.85, 0.95, 1.0, 1.05] across all groups.
Assign a single m and a coefficient for each unique value.y=m⋅exp(-a⋅x)
 
Compute y values using the equation for each group of 8 x values.

Inject Anomalies:

Introduce one anomaly per group by scaling down a randomly selected y value.
Prepare Data for Training:

Formulate features X by combining the new column, repeated x values, and computed y values.
Create labels y where normal data points are marked as 0 and anomalies as 1.
Standardize the features using StandardScaler.
Train the MLP Classifier:

Define an MLP classifier with 100 hidden units.
Train the classifier on the standardized data.

Predict and Evaluate:

Use the trained MLP classifier to predict labels.
Evaluate model performance using classification_report and confusion_matrix.
Plot the Results for Each Group:

Generate subplots using plt.subplots based on unique values in the new column.
For each subplot, visualize original data points with anomalies and predictions from the MLP classifier.
Adjust layout with plt.tight_layout and display plots using plt.show.
