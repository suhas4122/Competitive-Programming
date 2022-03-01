Output = Data1.copy()
Output = Output[Output["created_date"] == Output["created_date"].max()]

ear_table = Output.pivot(index="Label_ID", columns="Bucket_ID", values="Value")
labels = Output[["Particulars", "Inflow_Outflow", "Label_ID"]].drop_duplicates()
temp = pd.merge(ear_table, labels, on="Label_ID", how="left")
temp = temp.set_index("Label_ID")


ear_table = ear_table.replace(to_replace="nan", value="0.0")
ear_table.reset_index(level=0, inplace=True)

final_table = labels[["Particulars", "Label_ID"]].merge(ear_table, how="left")

buckets = Output[["Bucket_ID", "Bucket_Name"]].drop_duplicates()

bucket_ids = final_table.columns.to_list()
bucket_ids = pd.DataFrame({"Bucket_ID": bucket_ids})
merged_cols = pd.merge(
    bucket_ids, buckets[["Bucket_ID", "Bucket_Name"]], how="left", on="Bucket_ID",
)

z = final_table.columns.get_loc("Value")

merged_cols.iloc[0, 1] = merged_cols.iloc[0, 0]
merged_cols.iloc[1, 1] = merged_cols.iloc[1, 0]
merged_cols.iloc[z, 1] = merged_cols.iloc[z, 0]

final_table.columns = merged_cols["Bucket_Name"].to_list()

output_data = final_table












Output = Data1.copy()
Output = Output[Output["created_date"] == Output["created_date"].max()]

ear_table = Output.pivot(index="Label_ID", columns="Bucket_ID", values="Value")
labels = Output[["Particulars", "Inflow_Outflow", "Label_ID", "Reporting_Currency", "Report_Analysis_ID", "Val_Date"]].drop_duplicates()
temp = pd.merge(ear_table, labels, on="Label_ID", how="left")
temp = temp.set_index("Label_ID")


ear_table = ear_table.replace(to_replace="nan", value="0.0")
ear_table.reset_index(level=0, inplace=True)

final_table = labels[["Particulars", "Label_ID"]].merge(ear_table, how="left")

buckets = Output[["Bucket_ID", "Bucket_Name"]].drop_duplicates()

bucket_ids = final_table.columns.to_list()
bucket_ids = pd.DataFrame({"Bucket_ID": bucket_ids})
merged_cols = pd.merge(
    bucket_ids, buckets[["Bucket_ID", "Bucket_Name"]], how="left", on="Bucket_ID",
)

z = final_table.columns.get_loc("Value")

merged_cols.iloc[0, 1] = merged_cols.iloc[0, 0]
merged_cols.iloc[1, 1] = merged_cols.iloc[1, 0]
merged_cols.iloc[z, 1] = merged_cols.iloc[z, 0]

final_table.columns = merged_cols["Bucket_Name"].to_list()
final_table["entity"] = Data1["hierarchy_name"]
final_table["date"] = Data1["Val_Date"]
final_table["currency"] = Data1["Reporting_Currency"]
final_table["analysis_id"] = Data1["Report_Analysis_ID"]	
final_table["inflow_outflow"] = Data1["Inflow_Outflow"]	
final_table["Value"] = pd.to_numeric(final_table["Value"], errors='coerce')
output_data = final_table
