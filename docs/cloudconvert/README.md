# CloudConvert

cloudconvert support `.hwp` to `.docx` convert.

## for python

cloudconvert support python library. see [github repo](https://github.com/cloudconvert/cloudconvert-python)

### install

```shell
pip3 install cloudconvert
```

### usage

1. assign api key

    set env variable `CLOUDCONVERT_API_KEY` or assign your cloudconvert client.

    ```python
    import cloudconvert

    cloudconvert.configure(api_key='API_KEY', sandbox=False)
    ```

2. create job

    *AWS* *S3* usage is recommended.  
    it mentioned in [job create](https://cloudconvert.com/api/v2/jobs#jobs-create) in cloudconvert doc.  

    ```python
    """
    this code is mixed github code and api doc request body.
    """
    import cloudconvert


    cloudconvert.Job.create(payload={
    "tasks": {
        "import-my-file": {
        "operation": "import/s3"
        },
        "convert-my-file": {
        "operation": "convert",
        "input": "import-my-file",
        "input_format": "docx",
        "output_format": "pdf",
        "page_range": "1-2",
        "optimize_print": true
        },
        "export-my-file": {
        "operation": "export/s3",
        "input": "convert-my-file"
        }
    },
    "tag": "myjob-123"
    })
    ```

## Read more

- [job creation](https://cloudconvert.com/api/v2/jobs#jobs-create)
- [python library](https://github.com/cloudconvert/cloudconvert-python)